
#include "Include.h"





int sizeX = 3;
int sizeY = 3;
int numPlayers = 2;







int main(){

	Map map = Map();
	AI* ai = new AI(&map, 1);


	map.Draw();

	std::cin.get();
	return 0;
}


