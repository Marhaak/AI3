// STD
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
// SDL
#include "SDL.h"
#include "SDL_image.h"

bool done;
int board[3][3];
int player, winner;
int winXSize = 300;
int winYSize = 300;
SDL_Texture* textureSheet[2];		// Array with the textures
SDL_Window*   window;				// The window
SDL_Renderer* renderer;				// The renderer

void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) { // Parameters, x and y, define position in the projected window.
	SDL_Rect pos;
    pos.x = x;
    pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h); // Setup ups the image and shows it.
    SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Texture* loadImage(char* _file) { // Returns a pointer to the texture.
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(renderer, _file);
    if (tex == nullptr) { // Checks the pointer and print error.
		printf("Failed to load image: %s %s\n", _file, IMG_GetError());
		getchar();
	}
    return tex;
}

bool InitSDL() {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		return false;
	}

	// Creating the window
	window = SDL_CreateWindow("Tick Tack Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winXSize, winYSize, NULL);
    if (window == nullptr){
		printf("Something went wrong, with making the window for SDL");
		getchar();
		return false;
    }

	// Creating the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
		printf("Something went wrong, with making the renderer for SDL");
		getchar();
		return false;
    }

	// Loads all the pictures.
	textureSheet[0] = loadImage("blank.png");
	textureSheet[1] = loadImage("O.png");
	textureSheet[2] = loadImage("X.png");

	// Everything went ok
	return true;
}

void select(int &X, int &Y) { // Retrieves the clicked position and prepares it for usage.

	bool click = false;
	SDL_Event _event;

	while (click == false){
		while (SDL_PollEvent(&_event)) {
		
			// Get the mouse position on click.
			if (_event.type == SDL_MOUSEBUTTONDOWN && _event.button.button == SDL_BUTTON_LEFT){
				SDL_GetMouseState(&Y, &X);
				X = X/100;	Y = Y/100;
				click = true;
			}
			// On closing the window, exit.
			if (_event.type == SDL_QUIT){
				exit(0);
			}
		}
	}
}

void Draw(int _x, int _y, int _i) {
	// Draws to back buffer
	ApplySurface(_x, _y, textureSheet[_i], renderer);
}

int X(int pos) {
	return pos % 3;
}
 
int Y(int pos) {
	return pos / 3;
}

void set(int pos, int who) {
	board[Y(pos)][X(pos)] = who;
}

void set(int posX, int posY, int who) {
	board[posY][posX] = who;
}
 
void unset(int pos) {
	board[Y(pos)][X(pos)] = -1;
}

void unset(int posX, int posY) {
	board[posY][posX] = -1;
}

void printIntro() {
	printf(" _____ _           _____               _____          \n");
	printf("|_   _(_)         |_   _|             |_   _|         \n");
	printf("  | |  _  ___ ______| | __ _  ___ ______| | ___   ___ \n");
	printf("  | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\\n");
	printf("  | | | | (__       | | (_| | (__       | | (_) |  __/\n");
	printf("  \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___|\n");
	printf("                                                      \n");
}

void setup() { // Prepares the board and set ups the order of plays for the algorithm.
	printf("Input starting player(0 = AI first, 1 = Human first): "); // 0 = Ai first, 1 = Human first.
	scanf_s("%d", &player); 
	if (player != 0) {
		player = 1;
	}

	int i, j;
	for (i = 0; i < 3; i++) { 
		for (j = 0; j < 3; j++) {

			board[i][j] = -1;
		}
	}
	done = false;
	
	printf("\n\tStart Game...\n\n\n");
}
  
void printBoard() { // Prints the image related to the value in the array.

	int i, j;
	SDL_RenderClear(renderer); // Clears the screen before projecting images.
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			Draw(i * 100, j * 100, board[i][j]+1); // Draws the designated image.
		}
	}
	SDL_RenderPresent(renderer); // Renders the prepared images.
}
 
int checkGame() {
	int i, j;

	// Checking if the game is won Vertically
	for (i = 0; i < 3; i++) {
		int fl = board[i][0];
		for (j = 1; j < 3; j++) {
			if (board[i][j] != fl) {
				fl = -1;
			}
		}
		if (fl == -1) {
			continue;
		}
		winner = fl;
		return 1;
	}
 
	// Check if the game is won Horizontal
	for (i = 0; i < 3; i++) {
		int fl = board[0][i];
		for (j = 1; j < 3; j++) {
			if (board[j][i] != fl) {
				fl = -1;
			}
		}
		if (fl == -1) {
			continue;
		}
		winner = fl;
		return 1;
	}
	
	// Checking the game for diagonal winning
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != -1) {
		winner = board[0][0];
		return 1;
	} 
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != -1) {
		winner = board[1][1];
		return 1;
	}
 
	// If there is a free spot left
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == -1) {
				return 0;
			}
		}
	}
	winner = -1;
	return 1;
}
 
int testGame() {
	int i, j;

	// Checks if there is 3 in a row Vertically, and returns the winner if it's not empty
	for (i = 0; i < 3; i++) {
		int fl = board[i][0];
		for (j = 1; j < 3; j++) {
			if (board[i][j] != fl) {
				fl = -1;
			}
		}
		if (fl == -1) {
			continue;
		}
	return fl;
	}
 
	// Checks if there is 3 in a row Horizontally, and returns the winner if it's not empty
	for (i = 0; i < 3; i++) {

		int fl = board[0][i];
		for (j = 1; j < 3; j++) {
			if (board[j][i] != fl) {
				fl = -1;
			}
		}
		if (fl == -1) {
			continue;
		}
	return fl;
	}
 
	// Returns the winner if there is 3 in a row diagonally
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != -1) {
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != -1) {
		return board[1][1];
	}

	
	// Returns 2 if there is a free square
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == -1){
				return 2;
			}
		}
	}

	// Otherwise returns -1
	return -1;
}
 
void playerPlay() {

	// Print the board
	printBoard();
	// Register the spot to play in.
	int x; int y;
	do{
		printf("Click on a free square to play in.\n");
		select(x, y);
	}while (board[y][x] != -1);

	// Change the selected square
	set(x, y, player);
	printf("Played in: %d %d\n", x, y);
}
  
int AlphaBetaNegamax(int who, int &move, int a, int b) {
	
	int D = testGame(); // Checks the state of the game.
	
	// If the game have ended.
	if (D != 2) {

		// Returns a score, 0 = draw, 1 = wictory, -1 = lose
		if (D == -1) {
			return 0;
		} else if (D == who) {
			return 1;
		} else {
			return -1;
		}
	}

	// If the game haven't ended.
	int i, flag = 0;

	// Iterate trough all the possible moves, if they're possible
	for (i = 0; i < 9; i++) {
		if (board[Y(i)][X(i)] == -1) {

			// Tries a move
			set(i, who);
			int tmp;
			int score = -AlphaBetaNegamax(1 - who, tmp, -b, -a); // Recursive tries next move until a score is returned.
			
			// Undo the move
			unset(i);

			// If the result is victory or better
			if (score >= b) {
				move = i;
				return score;
			}
			// Finds the best possible solution that's not a victory.
			if (score > a || (score == a && flag == 0)) {
				move = i;
				a = score;
				flag = 1;
			}
		}
	}
	return a;
}
 
void aiPlay() { // Ai calculates his move and plays.
  int bx = 0;
  AlphaBetaNegamax(player, bx, -1, 1); // Calculates optimal move. Maximizes own score, minimazes human score.
  set(bx, player); // Sets the Ai's move.
  printf("Played in: %d %d\n", X(bx), Y(bx));
}
 
void play() {

	// It is the players turn
	if (player == 1) {
		playerPlay();
	} else {    // Its the AI's turn
		aiPlay();
	}
}
 
void printOutro() {
	// Prints the winner of the game.
	if( winner == 2) {
		printf("Game Winner: AI");
	} else {
		printf("Game Winner: Player");
	}
}

int main(int argc, char* argv[]) {
	// Initiates SDL
	if(!InitSDL()) {
		printf("Error!");
		return 0;
	}
	
	// Play game!
	bool restart;
	do{
		// Initiates game
		printIntro();
		setup();

		// While game is still playing
		while (!done) {
			play();
			player = 1 - player;
			if (checkGame()) {

				done = true;
			}
			printBoard();
		}

		// After game have ended, print winner and ask for restart.
		printOutro();
		char holder;
		printf("\nDo you want to try again? Y/N ");
		scanf_s(" %c", &holder, 1);

		// If yes, set the restart bool.
		if(toupper(holder) != 'Y') {
			restart = false;
		} else {
			restart = true;
			system("CLS");
		}
	} while (restart);
	return 0;
}
