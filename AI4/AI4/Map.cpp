#include "Include.h"

Map::Map(int _x, int _y) {

	//Creation of a gameboard the size of _x and _y
	for (int x = 0; x < _x; x++){
		std::vector<int> temp;
		for(int y = 0; y < _y; y++){
			temp.push_back(0);
		}
		gameboard.push_back(temp);
	}
}

Map::~Map(void) {
	//Mayhem
}

void Map::Draw() {

	//iterate trough all spaces on the board
	for(unsigned x = 0; x < gameboard.size(); x++) {
		for(unsigned y = 0; y < gameboard[0].size(); y++) {

			if(gameboard[x][y] == -1) { 
				std::cout << x; 
			} else { 
				std::cout << gameboard[x][y]; 
			}
		}
		std::cout << std::endl;
	}
}

int Map::Get(int _x, int _y) {

	if( _x < 0 || 
		_x > gameboard.size() || 
		_y < 0 || 
		_y > gameboard[0].size() ) {
		return -2; 
	} else { 
		return gameboard[_x][_y]; 
	}
}

int Map::Set(int _xy, int who) {

	if( Get(_xy, _xy) != -2 ) {
		gameboard[_xy][_xy] = who;
	}
	return 1;
}

int Map::Set(int _x, int _y, int who) {

	if( Get(_x, _y) != -2) {
		gameboard[_x][_y] = who;
	}
	return 1;
}