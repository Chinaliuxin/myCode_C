#include "Stack.h"
#include <assert.h>
#include <stdio.h>



void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}

// ��ջ
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if(MAX_SIZE == s->_top)
	{
		printf("ջ�������Ų���!!!\n");
		return;
	}

	s->_array[s->_top++] = data;
}

// ��ջ
void StackPop(Stack* s)
{
	if(StackEmpty(s))
		return;

	s->_top--;
}

// ��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
	assert(!StackEmpty(s));
	return s->_array[s->_top-1];
}

// ��ЧԪ�صĸ���
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

// ���ջ�Ƿ�Ϊ��
// ��ջ---0 
// �ǿ�---1
int StackEmpty(Stack* s)
{
	assert(s); 
	return s->_top == 0?0:1;
}

