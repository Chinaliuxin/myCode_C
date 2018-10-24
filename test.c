#include"game.h"



void menu()
{
	printf("*****************扫雷****************************\n");
	printf("***** 1.play           0.exit   *****************\n");
	printf("*************************************************\n");
}
void game()
{
	int quit = 1;
	char mine[ROWS][COLS] = { 0 };//雷
	char playersee[ROWS][COLS] = { 0 };//展示给玩家
 	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(playersee, ROWS, COLS, '*');
	SetMine(mine,ROW, COL);//放下雷
	printfBoard(playersee, ROW, COL);
	for (quit=1; quit != 0;)
	{
		char ok = 'c';
		printf("输入a进入扫雷模式，输入b进入插旗模式\n");
		scanf("%c", &ok);
		if (ok == 'b')
		{
            Flag(playersee, ROW, COL);
		}
		else if (ok == 'a')
		{
		    quit=KillMine(mine, playersee, ROW, COL);
		}
	}


}


int main()
{

	int input = 3;
	int i = 0;
	menu();
	printf("选择数字\n");
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出游戏");
			break; 
		default:
			printf("请重新选择数字来决定游戏进程\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
  }