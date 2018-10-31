#include "Stack.h"
#include <string.h>
#include <stdio.h>

#if 0
int IsBracket(char c)
{
	if( ('(' == c || ')' == c) ||
		('{' == c || '}' == c) ||
	    ('[' == c || ']' == c))
	{
	   return 1;
	}

	return 0;
}

int MatchBrackets(const char* pStr)
{
	int i = 0;
	int strLen = 0;
	Stack s;
	
	if(NULL == pStr)
		return 0;

	StackInit(&s);
	strLen = strlen(pStr);
	for(; i < strLen; ++i)
	{
		if(!IsBracket(pStr[i]))
			continue;
		else
		{
			if('(' == pStr[i] || '[' == pStr[i] || '{' == pStr[i])
			{
				StackPush(&s, pStr[i]);
			}
			else
			{
				char c;
				if(StackEmpty(&s))
				{
					printf("�����ű������Ŷ�\n");
					return 0;
				}

				c = StackTop(&s);
				if(('(' == c && ')' == pStr[i]) ||
				   ('[' == c && ']' == pStr[i]) ||
				   ('{' == c && '}' == pStr[i]))
				{
					StackPop(&s);
				}
				else
				{
					printf("�������Ŵ���ƥ��������\n");
					return 0;
				}
			}
		}
	}

	if(!StackEmpty(&s))
	{
		printf("�����ű������Ŷ�\n");
		return 0;
	}

	printf("��������������ƥ����ȷ\n");
	return 1;
}

void TestMatchBrackets()
{
	char a[] = "(())abc{[(])}" ;  // �������Ŵ���ƥ�䲻��ȷ
	char b[] = "(()))abc{[]}" ;   // �����Ŷ���������
	char c[] = "(()()abc{[]}" ;   // �����Ŷ���������
	char d[] = "(())abc{[]()}" ;  // ��������ƥ����ȷ
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
}
#endif


typedef enum {ADD, SUB, MUL, DIV, DATA}OPERATOR;

typedef struct Cell
{
	OPERATOR _op;
	int _data;
}Cell;


int CalcRPN(Cell RPN[], int size)
{
	int i = 0;
	Stack s;
	StackInit(&s);

	for(; i < size; ++i)
	{
		if(DATA == RPN[i]._op)
			StackPush(&s, RPN[i]._data);
		else
		{
			int left = 0, right = 0;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);

			switch(RPN[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left * right);
				break;
			case DIV:
				if(0 == right)
				{
					printf("����Ϊ0�Ƿ�\n");
					return 0;
				}

				StackPush(&s, left / right);
				break;
			}
		}
	}

	return StackTop(&s);
}

// 12*(3+4)-6+8/2 ���C> 12 3 4 + * 6 - 8 2 / +
// ��׺���ʽ���ת���ɺ�׺���ʽ��
void TestRPN()
{
	Cell RPN[] = {{DATA, 12},{DATA, 3}, {DATA, 4}, {ADD, 0},
	              {MUL,   0},{DATA, 6}, {SUB,  0}, {DATA, 8}, 
	              {DATA,  2},{DIV,  0}, {ADD,  0}};

	printf("%d\n", CalcRPN(RPN, sizeof(RPN)/sizeof(RPN[0])));
}