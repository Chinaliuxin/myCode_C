#include"game.h"


void printfBoard(char board[ROWS][COLS], int rows, int cols)//��ӡʱ������Χ1������߽�ֵ������
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
		int x = rand() % ROW + 1;//����������0-row֮��
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
		printf("ʹ������ı�ʾ����Ҫ�򿪵�����\n");
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
				printf("�㱻��ը��\n");
				return 0;

			}
			printfBoard(playersee, ROW, COL);

		}
		else
		{
			printf("�������\n");
		}
	//}
}
void Flag(char board[ROWS][COLS], int rows, int cols)
{

		int x = 0;
		int y = 0;
		printf("ʹ������ı�ʾ����Ҫ�Ĳ�������(����ȡ����������죩\n");
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
			printf("������������޷�����\n");
		}
		printfBoard(board, ROW, COL);//��ӡ����������

}