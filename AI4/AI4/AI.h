#pragma once
#include "Include.h"

class AI {
public:
	AI(Map *_map);
	~AI(void);
	int testGame();
private:
	Map *map;
};

