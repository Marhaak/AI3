#include "Include.h"


Map::Map(int _x, int _y){


	//Creation of a gameboard the size of _x and _y
	for (int x = 0; x < _x; x++){
		std::vector<int> temp;
		for(int y = 0; y < _y; y++){
			temp.push_back(-1);
		}
		gameboard.push_back(temp);
	}




}


Map::~Map(void){
	//Mayhem
}



void Map::Draw(){

	//iterate trough all spaces on the board
	for(unsigned x = 0; x < gameboard.size(); x++){
		for(unsigned y = 0; y < gameboard[0].size(); y++){

			if(gameboard[x][y] == -1){ std::cout << x; }
			else{ std::cout << gameboard[x][y]; }


		}
		std::cout << std::endl;
	}
}