#include "Include.h"

int sizeX = 3;
int sizeY = 3;
int numPlayers = 2;

int main(){

	AI ai = AI(sizeX, sizeY, numPlayers);
	
	ai.play();

	std::cin.get();

	return 0;
}
