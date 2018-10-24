#pragma once

typedef int DataType;
typedef unsigned int size_t;

typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity;   // 底层空间的大小
	size_t _size;       // 有效元素的个数
}SeqListD, *PSeqListD;


/////////////////////////////////////////////////
void SeqListDInit(PSeqListD pSeq);
void SeqListDPushBack(PSeqListD pSeq, DataType data);
void SeqListDPopBack(PSeqListD pSeq);
int SeqListDEmpty(PSeqListD pSeq);
int SeqListDSize(PSeqListD pSeq);
void SeqListDClear(PSeqListD pSeq);
int SeqListDCapacity(PSeqListD pSeq);
void SeqListDDestroy(PSeqListD pSeq);
int CheckCapacity(PSeqListD pSeq);



///////////////////////////////////////////////////
// .c
#include <malloc.h>
#include <stdio.h>
#include <string.h>
void SeqListDInit(PSeqListD pSeq)
{
	if(NULL == pSeq)
		return;

	//pSeq->_array = NULL;
	//pSeq->_capacity = 0;
	//pSeq->_size = 0;

	pSeq->_array = (DataType*)malloc(3 * sizeof(DataType));
	if(NULL == pSeq->_array)
		return;

	pSeq->_capacity = 3;
}

void SeqListDPushBack(PSeqListD pSeq, DataType data)
{
	if(NULL == pSeq)
		return;

	if(!CheckCapacity(pSeq))
		return;

	pSeq->_array[pSeq->_size++] = data;
}

void SeqListDPopBack(PSeqListD pSeq)
{
	if(SeqListDEmpty(pSeq))
		return;

	pSeq->_size--;
}


int CheckCapacity(PSeqListD pSeq)
{
	if(NULL == pSeq)
		return 0;

	if(pSeq->_size == pSeq->_capacity)
	{
		// 扩容
		size_t newCapacity = pSeq->_capacity*2;
		DataType* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if(NULL == pTemp)
			return 0;

		// 将旧空间中元素搬移到新空间
		memcpy(pTemp, pSeq->_array, pSeq->_size*sizeof(DataType));

		free(pSeq->_array);

		pSeq->_array = pTemp;
		pSeq->_capacity = newCapacity;
	}

	return 1;
}

int SeqListDEmpty(PSeqListD pSeq)
{
	return 0 == pSeq->_size;
}

int SeqListDSize(PSeqListD pSeq)
{
	return pSeq->_size;
}

int SeqListDCapacity(PSeqListD pSeq)
{
	return pSeq->_capacity;
}

void SeqListDClear(PSeqListD pSeq)
{
	pSeq->_size = 0;
}

void SeqListDDestroy(PSeqListD pSeq)
{
	if(pSeq->_array)
	{
		free(pSeq->_array);
		pSeq->_capacity = 0;
		pSeq->_size = 0;
	}
}

void PrintSeqListD(PSeqListD pSeq)
{
	size_t i = 0;
	for(; i < pSeq->_size; ++i)
		printf("%d ", pSeq->_array[i]);

	printf("\n");
}


void TestSeqListD()
{
	SeqListD s;
	SeqListDInit(&s);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	PrintSeqListD(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDPushBack(&s, 4);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDPopBack(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDClear(&s);
	printf("size = %d\n", SeqListDSize(&s));
	printf("capacity = %d\n", SeqListDCapacity(&s));

	SeqListDDestroy(&s);
}