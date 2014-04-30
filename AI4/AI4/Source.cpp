/*
*
* Copyright (c) Pedro Paredes (DCC/FCUP) 2012
*
* SuperTicTacToe is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SuperTicTacToe is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SuperTicTacToe. If not, see <http://www.gnu.org/licenses/>.
*/
 
#include <stdio.h> 
#include <stdlib.h>

 
bool done, clearFlag;
int board[3][3];
int player, winner;
 
int X(int pos)
{
  return pos % 3;
}
 
int Y(int pos)
{
  return pos / 3;
}
 
void set(int pos, int who)
{
  board[Y(pos)][X(pos)] = who;
}
 
void unset(int pos)
{
  board[Y(pos)][X(pos)] = -1;
}
 
/*void printIntro()
{
  printf(" _____ _           _____               _____          \n");
  printf("|_   _(_)         |_   _|             |_   _|         \n");
  printf("  | |  _  ___ ______| | __ _  ___ ______| | ___   ___ \n");
  printf("  | | | |/ __|______| |/ _` |/ __|______| |/ _ \\ / _ \\\n");
  printf("  | | | | (__       | | (_| | (__       | | (_) |  __/\n");
  printf("  \\_/ |_|\\___|      \\_/\\__,_|\\___|      \\_/\\___/ \\___|\n");
  printf("                                                      \n");
  printf("                                                      \n\n\t\tPedro Paredes (DCC/FCUP)\n\n");
}*/
 
void setup()
{
  printf("Input starting player: ");
  scanf_s("%d", &player);
  if (player != 0)
    player = 1;
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      board[i][j] = -1;
  done = false;
  char flag;
  printf ("Clear game board after each play? ");
  scanf_s(" %c", &flag);
  if (flag == 'y')
    clearFlag = true;
  else
    clearFlag = false;
  printf("\n\tStart Game...\n\n\n");
  getchar();
}
 
void clear()
{
  if (!clearFlag)
    return;
  system ("clear");
}
 
void printBoard()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    printf("\t");
    for (j = 0; j < 3; j++)
    {
      if (board[i][j] == -1)
	printf(" ");
      if (board[i][j] == 0)
	printf("O");
      if (board[i][j] == 1)
	printf("X");
      if (j != 2)
	printf("|");
    }
    printf("\n");
    if (i != 2)
      printf("\t-----\n");
  }
  printf("\n\n");
}
 
int checkGame()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    int fl = board[i][0];
    for (j = 1; j < 3; j++)
      if (board[i][j] != fl)
	fl = -1;
    if (fl == -1)
      continue;
    winner = fl;
    return 1;
  }
 
  for (i = 0; i < 3; i++)
  {
    int fl = board[0][i];
    for (j = 1; j < 3; j++)
      if (board[j][i] != fl)
	fl = -1;
    if (fl == -1)
      continue;
    winner = fl;
    return 1;
  }
 
  if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != -1)
  {
    winner = board[0][0];
    return 1;
  }
 
  if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != -1)
  {
    winner = board[1][1];
    return 1;
  }
 
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (board[i][j] == -1)
	return 0;
  winner = -1;
  return 1;
}
 
int testGame()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    int fl = board[i][0];
    for (j = 1; j < 3; j++)
      if (board[i][j] != fl)
	fl = -1;
    if (fl == -1)
      continue;
    return fl;
  }
 
  for (i = 0; i < 3; i++)
  {
    int fl = board[0][i];
    for (j = 1; j < 3; j++)
      if (board[j][i] != fl)
	  fl = -1;
    if (fl == -1)
      continue;
    return fl;
  }
 
  if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != -1)
    return board[0][0];
 
  if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != -1)
    return board[1][1];
 
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (board[i][j] == -1)
	return 2;
  return -1;
}
 
void opPlay()
{
  printBoard();
  printf("Select a box to play in: ");
  int bx;
  scanf_s("%d", &bx);
  while (board[Y(bx)][X(bx)] != -1)
  {
    printf("Box aready taken...\n");
    scanf_s("%d", &bx);
  }
  getchar();
  set(bx, player);
  clear();
  printf("Played in: %d %d\n", X(bx), Y(bx));
}
 
int negamax(int who, int &move)
{
  int D = testGame();
  if (D != 2)
  {
    if (D == -1)
      return 0;
    if (D == who)
      return 1;
    else
      return -1;
  }
  int bestScore = -1, i;
  for (i = 0; i < 9; i++)
    if (board[Y(i)][X(i)] == -1)
    {
      set(i, who);
      int tmp;
      int score = -negamax(1 - who, tmp);
      if (score > bestScore)
      {
	bestScore = score;
	move = i;
      }
      unset(i);
    }
  return bestScore;
}
 
int AlphaBetaNegamax(int who, int &move, int a, int b)
{
  int D = testGame();
  if (D != 2)
  {
    if (D == -1)
      return 0;
    if (D == who)
      return 1;
    else
      return -1;
  }
  int i, flag = 0;
  for (i = 0; i < 9; i++)
    if (board[Y(i)][X(i)] == -1)
    {
      set(i, who);
      int tmp;
      int score = -AlphaBetaNegamax(1 - who, tmp, -b, -a);
      unset(i);
      if (score >= b)
      {
	move = i;
	return score;
      }
      if (score > a || (score == a && flag == 0))
      {
	move = i;
	a = score;
	flag = 1;
      }
    }
  return a;
}
 
void myPlay()
{
  int bx = 0;
//  ABnegamax(player, bx, -1, 1);
  negamax(player, bx);
  set(bx, player);
  printf("Played in: %d %d\n", X(bx), Y(bx));
}
 
void play()
{
  if (player == 1)
    opPlay();
  else
    myPlay();
}
 
void printOutro()
{
  clear();
 // printIntro();
  printf("Game Winner: %d\n", winner);
}
 
/*
int main()
{
  printIntro();
  setup();
  while (!done)
  {
    clear();
    play();
    player = 1 - player;
    if (checkGame())
      done = true;
    printBoard();
    getchar();
  }
  printOutro();
  return 0;
}
*/