#pragma once
#include "Include.h"



class Map {
private:
	std::vector< std::vector<int> > gameboard;



public:
	
	Map(int _x = 3, int _y = 3);
	~Map(void);

	void Draw();
	int Get(int _x, int _y);
	int Set(int _xy, int who);
	int Set(int _x, int _y, int who);	

};

