#pragma once
#include "Include.h"

class AI {
public:
	AI(Map *_map);
	~AI(void);
	void play();
private:
	Map *map;
	int testGame();
};

