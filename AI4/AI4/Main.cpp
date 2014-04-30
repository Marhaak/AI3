#include "Include.h"

int sizeX = 3;
int sizeY = 3;
int numPlayers = 0;

void printIntro()
{
  printf(" _____ _           _____               _____          \n");
  printf("|_   _(_)         |_   _|             |_   _|         \n");
  printf("  | |  _  ___ ______| | __ _  ___ ______| | ___   ___ \n");
  printf("  | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\\n");
  printf("  | | | | (__       | | (_| | (__       | | (_) |  __/\n");
  printf("  \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___|\n");
  printf("                                                      \n");
}


int main(){

	printIntro();

	AI* ai = new AI(sizeX, sizeY, numPlayers);
	
	ai->play();



	std::cin.get();

	return 0;
}
