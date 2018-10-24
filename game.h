#ifndef __GAME_H__
#define __GAME_H__

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 18



void Flag(char board[ROWS][COLS], int rows, int cols);
void printfBoard(char board[ROWS][COLS], int rows, int cols);
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
int SetMine(char board[ROWS][COLS], int row, int col);
int KillMine(char board[ROWS][COLS],  char playersee[ROWS][COLS], int row, int col);
#endif
