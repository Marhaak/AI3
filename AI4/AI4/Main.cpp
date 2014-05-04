//#include "Include.h"
//
//int sizeX = 3;
//int sizeY = 3;
//int playerNumber, test = 0;
//Map *map;
//
//void printIntro()
//{
//  printf(" _____ _           _____               _____          \n");
//  printf("|_   _(_)         |_   _|             |_   _|         \n");
//  printf("  | |  _  ___ ______| | __ _  ___ ______| | ___   ___ \n");
//  printf("  | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\\n");
//  printf("  | | | | (__       | | (_| | (__       | | (_) |  __/\n");
//  printf("  \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___|\n");
//  printf("                                                      \n");
//}
//
//int testGame();
//int negamax(int who, int &move);
//int AlphaBetaNegamax(int who, int &move, int a, int b);
//int X(int pos);
//int Y(int pos);
//void aiPlay();
//
//
//int main(){
//	//map = new Map(sizeX, sizeY);
//	printIntro();
//
//	AI* ai = new AI(sizeX, sizeY, 0);
//	
//	ai->play();
//	//aiPlay();
//
//	std::cin.get();
//
//	return 0;
//}
//
//int testGame(){
//  
//	int i, j;
//
//	for (i = 0; i < 3; i++) {
//		int fl = map->Get(i, 0);
//		for (j = 1; j < 3; j++) {
//			if (map->Get(i, j) != fl) {
//				fl = -1;
//			}
//		}
//		if (fl == -1){
//			continue;
//		}
//		return fl;
//	}
// 
//	for (i = 0; i < 3; i++) {
//		int fl = map->Get(0, i);
//		for (j = 1; j < 3; j++) {
//			if (map->Get(j, i) != fl) {
//				fl = -1;
//			}
//		}
//
//		if (fl == -1) {
//			continue;
//		}
//		return fl;
//	}
// 
//
//	//Check the diagonal lines
//	if (map->Get(0, 0) == map->Get(1, 1) && 
//		map->Get(2, 2) == map->Get(1, 1) && 
//		map->Get(0, 0) != -1) {
//		return map->Get(0, 0);
//	}
//
//	if (map->Get(0, 2) == map->Get(1, 1) && 
//		map->Get(2, 0) == map->Get(1, 1) && 
//		map->Get(1, 1) != -1) {
//		return map->Get(1, 1);
//	}
//
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 3; j++) {
//			if (map->Get(i, j) == -1) {
//				return 2;
//			}
//		}
//	}
//
//	return -1;
//}
//
//void aiPlay() {
//
//	int bx = 0;
//    //AlphaBetaNegamax(playerNumber, bx, -1, 1);
//	negamax(playerNumber, bx);
//	map->Set(bx, playerNumber);
//	printf("Played in: %d %d\n", X(bx), Y(bx));
//}
//
//int negamax(int who, int &move) {
//	std::cout<< test++<< "\n";
//	int D = testGame();
//
//	if (D != 2) {
//
//		if (D == -1) {
//		  return 0;
//		}
//		if (D == who) {
//		  return 1;
//		} else {
//		  return -1;
//		}
//	}
//
//	int bestScore = -1, i;
//
//	for (i = 0; i < 9; i++) {
//		if (map->Get(Y(i), X(i)) == -1) {
//
//			map->Set(i, who);
//			int tmp;
//			int score = -negamax(1 - who, tmp);
//			if (score > bestScore) {
//
//				bestScore = score;
//				move = i;
//			}
//		map->Set(i, -1);
//		}
//	}
//	return bestScore;
//}
//
//int AlphaBetaNegamax(int who, int &move, int a, int b) {
//	//std::cout<< test++<< "\n";
//	int D = testGame(), i, flag;
//	if (D != 2) {
//		if (D == -1){
//		  return 0;
//		}
//		if (D == who){
//		  return 1;
//		} else {
//
//		  return -1;
//		}
//	}
//	flag = 0;
//	for (i = 0; i < 9; i++) {
//		if (map->Get(Y(i), X(i)) == -1) {
//			map->Set(i, who);
//			int tmp;
//			int score = -AlphaBetaNegamax(1 - who, tmp, -b, -a);
//			map->Set(i, -1);
//			
//			if (score >= b) {
//				move = i;
//				return score;
//			}
//
//			if (score > a || (score == a && flag == 0)) {
//				move = i;
//				a = score;
//				flag = 1;
//			}
//		}
//	}
//	return a;
//}
//
//int X(int pos) {
//	return pos % 3;
//}
//
//int Y(int pos) {
//	return pos / 3;
//}
