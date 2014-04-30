#include "Include.h"

int sizeX = 3;
int sizeY = 3;
int numPlayers = 2;

int main(){


	Map map = Map(3,3);
	AI ai = AI(&map, 2);

	map.Draw();
	
	ai.play();

	

	std::cin.get();

	return 0;
}
