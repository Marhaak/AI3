#include "AI.h"


AI::AI(Map *_map) {
	_map = map;
}


AI::~AI(void)
{
}

int AI::testGame()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    int fl = map->Return(i, 0);
    for (j = 1; j < 3; j++)
      if (map->Return(i, j) != fl)
	fl = -1;
    if (fl == -1)
      continue;
    return fl;
  }
 
  for (i = 0; i < 3; i++)
  {
    int fl = map->Return(0, i);
    for (j = 1; j < 3; j++)
      if (map->Return(j, i) != fl)
	fl = -1;
    if (fl == -1)
      continue;
    return fl;
  }
 
  if (map->Return(0, 0) == map->Return(1, 1) && map->Return(2, 2) == map->Return(1, 1) && map->Return(0, 0) != -1)
    return map->Return(0, 0);
 
  if (map->Return(0, 2) == map->Return(1, 1) && map->Return(2, 0) == map->Return(1, 1) && map->Return(1, 1) != -1)
    return map->Return(1, 1);
 
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (map->Return(i, j) == -1)
	return 2;
  return -1;
}

void AI::play() {

	int bx = 0;
//  ABnegamax(player, bx, -1, 1);
	negamax(player, bx);
	Set(bx, player);
	printf("Played in: %d %d\n", X(bx), Y(bx));
}

int AI::negamax(int who, int &move) {

	int D = testGame();
	if (D != 2) {

		if (D == -1) {
		  return 0;
		}
		if (D == who) {
		  return 1;
		} else {

		  return -1;
		}
	}
	int bestScore = -1, i;
	for (i = 0; i < 9; i++) {
		if (map->Get(Y(i), X(i)) == -1) {

			map->Set(i, who);
			int tmp;
			int score = -negamax(1 - who, tmp);
			if (score > bestScore) {

				bestScore = score;
				move = i;
			}
		map->Set(i, -1);
		}
	}
  return bestScore;
}

int AI::AlphaBetaNegamax(int who, int &move, int a, int b) {

	int D = testGame();
	if (D != 2) {
		if (D == -1){
		  return 0;
		}
		if (D == who){
		  return 1;
		} else {

		  return -1;
		}
	}
	int i, flag = 0;
	for (i = 0; i < 9; i++) {
		if (map->Get(Y(i), X(i)) == -1) {
			map->Set(i, who);
			int tmp;
			int score = -AlphaBetaNegamax(1 - who, tmp, -b, -a);
			map->Set(i, -1);
			if (score >= b)
			{
				move = i;
				return score;
			}
			if (score > a || (score == a && flag == 0)) {
				move = i;
				a = score;
				flag = 1;
			}
		}
	}
	return a;
}