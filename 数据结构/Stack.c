#include "Stack.h"
#include <assert.h>
#include <stdio.h>



void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}

// 入栈
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if(MAX_SIZE == s->_top)
	{
		printf("栈已满，放不了!!!\n");
		return;
	}

	s->_array[s->_top++] = data;
}

// 出栈
void StackPop(Stack* s)
{
	if(StackEmpty(s))
		return;

	s->_top--;
}

// 获取栈顶元素
DataType StackTop(Stack* s)
{
	assert(!StackEmpty(s));
	return s->_array[s->_top-1];
}

// 有效元素的个数
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

// 检测栈是否为空
// 空栈---0 
// 非空---1
int StackEmpty(Stack* s)
{
	assert(s); 
	return s->_top == 0?0:1;
}

