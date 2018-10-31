#pragma once

//typedef int DataType;

//typedef struct Position
//{
//	int _x;
//	int _y;
//}Position;

//typedef Position DataType;

//typedef char DataType;

#define  MAX_SIZE 100


// ����һ����̬ջ
extern struct BinTreeNode;

typedef struct BinTreeNode* PBTNode;

typedef PBTNode DataType;

typedef struct Stackxxa
{
    DataType _array[MAX_SIZE];//DataType *_a;
	int _top; // ��ʾ��ЧԪ�ظ��� ��ʾջ��λ��
}Stack;


void StackInit(Stack* s);

// ��ջ
void StackPush(Stack* s, DataType data);

// ��ջ
void StackPop(Stack* s);

// ��ȡջ��Ԫ��
DataType StackTop(Stack* s);

// ��ЧԪ�صĸ���
int StackSize(Stack* s);

// ���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s);


