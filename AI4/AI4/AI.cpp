#include "AI.h"


AI::AI(Map *_map) {
	_map = map;
}


AI::~AI(void)
{
}

int AI::testGame(){
  
	int i, j;

	for (i = 0; i < 3; i++){
		int fl = map->Get(i, 0);
		for (j = 1; j < 3; j++){
			if (map->Get(i, j) != fl){
				fl = -1;
			}
		}
		if (fl == -1){
			continue;
		}
		return fl;
	}
 
	for (i = 0; i < 3; i++){
		int fl = map->Get(0, i);
		for (j = 1; j < 3; j++){
			if (map->Get(j, i) != fl){
				fl = -1;
			}
		}
		if (fl == -1){
			continue;
		}
		return fl;
	}
 

	//Check the diagonal lines
	if (map->Get(0, 0) == map->Get(1, 1) && map->Get(2, 2) == map->Get(1, 1) && map->Get(0, 0) != -1)
		return map->Get(0, 0);
 
	if (map->Get(0, 2) == map->Get(1, 1) && map->Get(2, 0) == map->Get(1, 1) && map->Get(1, 1) != -1)
		return map->Get(1, 1);
 


	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (map->Get(i, j) == -1){
				return 2;
			}
		}
	}
	return -1;
}
