#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row,int col)//初始化棋盘，使其存储为空格，并方便以后存储棋子
{
int i = 0, j = 0;
for (i = 0; i < row; i++)
{
	for (j = 0; j < col; j++)
	{
		board[i][j] = ' ';
	}
}
}
void PrintfBoard(char board[ROW][COL], int row, int col)
{

	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != ROW - 1)
		{
			printf("---|---|---\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;

	while (1)
	{
		printf("玩家下棋\n");
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if (x >= 0 && x < ROW && y >= 0 && y < COL)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = 'X';
				break;
			}
			else
			{
				printf("你所输入的坐标已有棋子\n");
				continue;
			}
		}
		else
		{
			printf("你输入的坐标超出了棋盘范围，请重新输入\n");
			continue;
		}

	}
}
void PcMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	//srand((unsigned int)time(NULL));
	//x = rand() % row;
	//y = rand() % col;
	while (1)
	{
		srand((unsigned int)time(NULL));
		x = rand() % row;
		y = rand() % col;
		if (board[1][1] == ' ')
		{
			board[1][1] = 'O';
			break;
		}
		if (board[1][1] != ' '&&board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
int CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				flag++;
			}
		}
	}


	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))//对角线判断
	{
		{
			if (board[1][1] == 'X')
			{
				return -1;
			}
			else if (board[1][1] == 'O')
			{
				return 1;
			}
		}

	}
	for (i = 0; i < row; i++)//行判断
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X' || board[i][1] == 'X' || board[i][2] == 'X')
			{
				return -1;
			}
			if (board[i][0] == 'O' || board[i][1] == 'O' || board[i][2] == 'O')
			{
				return 1;
			}
		}
	}
	for (j = 0; j < col; j++)//列判断
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] == 'X' || board[1][j] == 'X' || board[2][j] == 'X')
			{
				return -1;
			}
			if (board[0][j] == 'O' || board[1][j] == 'O' || board[2][j] == 'O')
			{
				return 1;
			}
		}
	}


	if (flag == row*col)//和棋判断
	{
		printf("和棋\n");
		return 0;
	}
}
