#pragma once


#define MAX_SIZE 10000
typedef unsigned int size_t;
typedef int DataType;

typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size;   // 顺序表中有效元素的个数
}SeqList, *PSeqList;

//typedef struct SeqList SeqList;

///////////////////////////////////////////////////
// .h
void SeqListInit(PSeqList ps);
void SeqListPushBack(PSeqList ps, DataType data);
void SeqListPopBack(PSeqList ps);
void SeqListPushFront(PSeqList ps, DataType data);
void SeqListPopFront(PSeqList ps);
void SeqListInsert(PSeqList ps, size_t pos, DataType data);
void SeqListErase(PSeqList ps, size_t pos);
int SeqListFind(PSeqList ps, DataType data);
void SeqListRemove(PSeqList ps, DataType data);
void SeqListRemoveAll(PSeqList ps, DataType data);
int SeqListEmpty(PSeqList ps);
int SeqListSize(PSeqList ps);


void PrintSeqList(PSeqList ps);
void BubbleSort(int* array, int size);
////////////////////////////////////////////////////
//.c
#include <assert.h>
#include <stdio.h>
void SeqListInit(PSeqList ps)
{
	if(NULL == ps)
		return;

	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)
{
#if 0
	if(NULL == ps)
		return;

	if(ps->_size == MAX_SIZE)
		return;

	ps->_array[ps->_size++] = data;
#else
	SeqListInsert(ps, ps->_size, data);
#endif
}

void SeqListPopBack(PSeqList ps)
{
#if 0
	if(SeqListEmpty(ps))
		return;

	ps->_size--;
#else
	SeqListErase(ps, ps->_size-1);
#endif
}

void SeqListPushFront(PSeqList ps, DataType data)
{
#if 0
	int i;
	assert(ps);
	if(ps->_size >= MAX_SIZE)
	{
		printf("顺序表已经满了!!!\n");
		return;
	}

	/*
	// 搬移元素
	for(i = ps->_size-1; i >= 0; --i)
		ps->_array[i+1] = ps->_array[i];
		*/

	// 搬移元素
	for(i = ps->_size; i > 0; --i)
		ps->_array[i] = ps->_array[i-1];

	// 插入新元素
	ps->_array[0] = data;
	ps->_size++;
#else
	SeqListInsert(ps, 0, data);
#endif
}

void SeqListPopFront(PSeqList ps)
{
#if 0
	int i = 0;
	assert(ps);
	if(SeqListEmpty(ps))
		return;

#if 0
	// 从前往后搬移元素
	for(i = 0; i < ps->_size-1; ++i)
		ps->_array[i] = ps->_array[i+1];
#endif

	// 从前往后搬移元素
	for(i = 1; i < ps->_size; ++i)
		ps->_array[i-1] = ps->_array[i];

	ps->_size--;
#else
	SeqListErase(ps, 0);
#endif
}

void SeqListInsert(PSeqList ps, size_t pos, DataType data)
{
	int i;
	assert(ps);
	if(pos > ps->_size)
		return;

	if(ps->_size >= MAX_SIZE)
	{
		printf("顺序表已经满了!!!\n");
		return;
	}

	/*
	// 搬移元素
	for(i = ps->_size-1; i >= 0; --i)
		ps->_array[i+1] = ps->_array[i];
		*/

	// 搬移元素
	for(i = ps->_size; i > pos; --i)
		ps->_array[i] = ps->_array[i-1];

	// 插入新元素
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeqList ps, size_t pos)
{
	int i;
	assert(ps);
	if(pos >= ps->_size)
		return;

	for(i = pos+1; i < ps->_size; ++i)
		ps->_array[i-1] = ps->_array[i];

	ps->_size--;
}

int SeqListEmpty(PSeqList ps)
{
	assert(ps);

	return 0 == ps->_size;
}

int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	assert(ps);

	for(; i < ps->_size; ++i)
	{
		if(data == ps->_array[i])
			return i;
	}

	return -1;

}

void SeqListRemove(PSeqList ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int count = 0, i = 0;
	assert(ps);

	for(; i < ps->_size; ++i)
	{
		if(ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}

	ps->_size -= count;
}



////////////////////////////////////////////
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	assert(ps);
	for(; i < ps->_size; ++i)
		printf("%d ", ps->_array[i]);

	printf("\n");
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

int Greater(int left, int right)
{
	return left > right;
}

int Less(int left, int right)
{
	return left < right;
}

typedef int (*Com)(int left, int right);



void BubbleSort(int* array, int size, Com Compare)
{
	int i = 0;
	int j = 0;
	for(; i < size-1; ++i)
	{
		// 冒泡的方法
		int IsChange = 0;
		for(j = 1; j < size - i; ++j)
		{
			if(Compare(array[j-1],array[j]))
			{
				Swap(&array[j], &array[j-1]);
				IsChange = 1;
			}
		}

		if(!IsChange)
			return;
	}
}

void SelectSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	int maxPos = 0;

	for(; i < size-1; ++i)
	{
		maxPos = 0;
		for(j = 1; j < size - i; ++j)
		{
			if(array[maxPos] < array[j])
				maxPos = j;
		}

		if(maxPos != size - 1 - i)
			Swap(&array[maxPos], &array[size-i-1]);
	}
}

// 找 bug
void SelectSort_OP(int* array, int size)
{
	int begin = 0;
	int end = size-1;
	int maxPos = 0;
	int minPos = 0;

	while(begin < end)
	{
		maxPos = begin;
		minPos = begin;
		int j = begin+1;
		while(j <= end)
		{
			if(array[maxPos] < array[j])
				maxPos = j;

			if(array[minPos] > array[j])
				minPos = j;

			j++;
		}

		if(maxPos != end)
			Swap(&array[maxPos], &array[end]);

		if(minPos == end)
			minPos = maxPos;

		if(minPos != begin)
			Swap(&array[minPos], &array[begin]);

		begin++;
		end--;
	}
}





///////////////////////////////////////////////
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListRemove(&s, 3);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListRemove(&s, 8);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListInsert(&s, 3, 6);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListErase(&s, 3);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListPushFront(&s, 0);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListPopFront(&s);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("size = %d\n", s._size);
	PrintSeqList(&s);
}

void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);

	PrintSeqList(&s);

	SeqListRemoveAll(&s, 2);
	PrintSeqList(&s);
}

void TestSeqList3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 3);
	PrintSeqList(&s);

	//BubbleSort(s._array, SeqListSize(&s), Less);
	SelectSort(s._array, SeqListSize(&s));
	PrintSeqList(&s);
}