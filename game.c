#include"game.h"


void printfBoard(char board[ROWS][COLS], int rows, int cols)//打印时，留周围1个方便边界值检索雷
{

	int i = 1;
	int j = 1;
	printf("  ");
	for (i = 1; i<= cols; i++)
	{
		printf("%2d", i);
		if (i==cols)
		{
			printf("\n");
		}
	}
	for (i = 1; i <=rows; i++)
	{
		printf("%20d", i);
		for (j = 1; j <=cols;j++)
		{
			printf("%2c",board[i][j]);
		
		}
		printf("\n");
	}
	printf("\n---------------------------\n");
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <  rows; i++)
	{
		for (j = 0; j < cols; j++)
		{                                                                                                                                                                                                                                                                                                                                                                                   
			board[i][j] = set;	
		}
	}

}

int SetMine(char board[ROWS][COLS], int row, int col)
{
	int sum = 0;
	srand((unsigned)time(NULL));
	for (sum = 0; sum < MINE;)
	{
		int x = rand() % ROW + 1;//产生数字在0-row之间
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			sum++;
		}

	}
}

int KillMine(char board[ROWS][COLS], char playersee[ROWS][COLS],int row, int col)
{
	//for (;;)
	//{
		int x = 0;
		int y = 0;
		printf("使用坐标的表示你想要打开的区域\n");
		scanf("%d%d", &x, &y);
		int i = 0;
		int j = 0;
		char sum = '0';
		for (i = x - 1; i <=x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				sum += board[i][j]-'0';
			}
		} 
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x][y] == '0')
			{
				playersee[x][y] = sum;
			}
			else
			{
				printf("你被雷炸死\n");
				return 0;

			}
			printfBoard(playersee, ROW, COL);

		}
		else
		{
			printf("坐标错误\n");
		}
	//}
}
void Flag(char board[ROWS][COLS], int rows, int cols)
{

		int x = 0;
		int y = 0;
		printf("使用坐标的表示你想要的插旗区域(或者取消你所插的旗）\n");
		scanf("%d%d", &x, &y);
		if (board[x][y] =='*')
		{
			board[x][y] = 'A';
		}
		else if (board[x][y] =='A')
		{
			board[x][y] = '*';
		}
		else if (board[x][y] != 'A' && board[x][y] != '*')
		{
			printf("你输入的坐标无法插旗\n");
		}
		printfBoard(board, ROW, COL);//打印插旗后的棋盘

}