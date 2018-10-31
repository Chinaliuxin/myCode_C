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


// 这是一个静态栈
extern struct BinTreeNode;

typedef struct BinTreeNode* PBTNode;

typedef PBTNode DataType;

typedef struct Stackxxa
{
    DataType _array[MAX_SIZE];//DataType *_a;
	int _top; // 表示有效元素个数 表示栈顶位置
}Stack;


void StackInit(Stack* s);

// 入栈
void StackPush(Stack* s, DataType data);

// 出栈
void StackPop(Stack* s);

// 获取栈顶元素
DataType StackTop(Stack* s);

// 有效元素的个数
int StackSize(Stack* s);

// 检测栈是否为空
int StackEmpty(Stack* s);


