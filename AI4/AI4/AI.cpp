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
