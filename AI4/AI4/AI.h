#pragma once
#include "Include.h"

class AI {
public:
	AI(int _x = 3, int _y = 3, int _player = 2);
	~AI(void);
	void play();
private:

	/* Variables */
	int playerNumber, test, depth;
	//Map* map;
	int map[3][3];

	/* Functions */

	int testGame();
	int negamax(int who, int &move);
	int AlphaBetaNegamax(int who, int &move, int a, int b);
	int X(int pos);
	int Y(int pos);
	
};
