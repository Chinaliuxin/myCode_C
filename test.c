#include"game.h"



void menu()
{
	printf("*****************ɨ��****************************\n");
	printf("***** 1.play           0.exit   *****************\n");
	printf("*************************************************\n");
}
void game()
{
	int quit = 1;
	char mine[ROWS][COLS] = { 0 };//��
	char playersee[ROWS][COLS] = { 0 };//չʾ�����
 	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(playersee, ROWS, COLS, '*');
	SetMine(mine,ROW, COL);//������
	printfBoard(playersee, ROW, COL);
	for (quit=1; quit != 0;)
	{
		char ok = 'c';
		printf("����a����ɨ��ģʽ������b�������ģʽ\n");
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
	printf("ѡ������\n");
	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("���˳���Ϸ");
			break; 
		default:
			printf("������ѡ��������������Ϸ����\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
  }