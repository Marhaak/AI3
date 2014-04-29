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
	int negamax(int who, int &move);
	int AlphaBetaNegamax(int who, int &move, int a, int b);
	int X(int pos);
	int Y(int pos);
};

