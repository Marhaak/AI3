#pragma once
#include "Include.h"

class AI {
public:
	AI(Map *_map, int _player);
	~AI(void);
	void play();
private:
	/* Variables */
	int playerNumber;

	/* Functions */
	
	Map *map;
	int testGame();
	int negamax(int who, int &move);
	int AlphaBetaNegamax(int who, int &move, int a, int b);
	int X(int pos);
	int Y(int pos);
	
};

