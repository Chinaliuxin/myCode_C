#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*************************************************\n");
	printf("***** 1.play           0.exit   *****************\n");
	printf("*************************************************\n");
}
int game()
{
	int judge = 2;
	char board[ROW][COL] = {0};
	InitBoard(board, ROW, COL);
	PrintfBoard(board,ROW,COL);
	do  
	{

		PlayerMove(board, ROW, COL);
		PrintfBoard(board, ROW, COL);
		judge=CheckWin(board, ROW, COL);
		if (judge == 1 || judge == 0 || judge == -1)
		{
			return judge;
		}
		PcMove(board, ROW, COL);
		PrintfBoard(board, ROW, COL);
		judge=CheckWin(board, ROW, COL); //0和棋  -1玩家赢   1电脑赢
		if (judge == 1 || judge == 0 || judge == -1)
		{
			return judge;
		}

	} while (1);

}
 void Result(int judge)
{
	if (1 == judge)
	{
		printf("你输了");
	}
	if (-1 == judge)
	{
		printf("你赢了");
	}
}
int main()
{
	int input = 3;
	int i = 0;
	menu();
	printf("选择数字来决定游戏进程\n");
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		  i = game();
			Result(i);
			break;
		case 0:
			printf("已退出游戏");
			break;
		default:
			printf("请重新选择数字来决定游戏进程\n");
		}
	} while (input);

	system("pause");
	return 0;
}