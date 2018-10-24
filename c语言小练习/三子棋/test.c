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
		judge=CheckWin(board, ROW, COL); //0����  -1���Ӯ   1����Ӯ
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
		printf("������");
	}
	if (-1 == judge)
	{
		printf("��Ӯ��");
	}
}
int main()
{
	int input = 3;
	int i = 0;
	menu();
	printf("ѡ��������������Ϸ����\n");
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		  i = game();
			Result(i);
			break;
		case 0:
			printf("���˳���Ϸ");
			break;
		default:
			printf("������ѡ��������������Ϸ����\n");
		}
	} while (input);

	system("pause");
	return 0;
}