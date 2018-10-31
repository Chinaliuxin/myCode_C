#pragma once
#include <assert.h>
#include <malloc.h>

// 带头结点的单链表
typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;


PNode BuyNodeH(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		assert(pNewNode);
		return NULL;
	}
}

// 指针  结构体   函数
void SListInitH(PNode* pHead)
{
	assert(pHead);
	*pHead = BuyNodeH(0);
}

void SListHPushBack(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while(pCur->_pNext)
		pCur = pCur->_pNext;

	pCur->_pNext = BuyNodeH(data);
}

void SListHPushFront(PNode pHead, DataType data)
{
	PNode pNewNode = BuyNodeH(data);
	pNewNode->_pNext = pHead->_pNext;
	pHead = pNewNode;
}

void PopFront(PNode pHead)
{
	PNode pDelNode = NULL;
	assert(pHead);
	pDelNode = pHead->_pNext;
	if(pDelNode)
	{
		pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}




