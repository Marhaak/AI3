#pragma once
#include "Include.h"



class Map {
private:
	std::vector< std::vector<int> > gameboard;



public:
	
	Map(int _x = 3, int _y = 3);
	~Map(void);

	void Draw();
	

};

