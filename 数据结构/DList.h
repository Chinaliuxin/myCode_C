#pragma once
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DataType _data;
}DLNode, *PDLNode;



//////////////////////////////////////////////////////
// 带头结点的双向链表
void DListInit(PDLNode* pHead);
void DListPushBack(PDLNode pHead, DataType data);
void DListPopBack(PDLNode pHead);
void DListPushFront(PDLNode pHead, DataType data);
void DListPopFront(PDLNode pHead);
void DListInsert(PDLNode pos, DataType data);
void DListErase(PDLNode pos);
PDLNode DListFind(PDLNode pHead, DataType data);
int DListEmpty(PDLNode pHead);
int DListSize(PDLNode pHead);

// 只清空有效结点，不删除头结点
void DListClear(PDLNode pHead);

// 1. 销毁链表中的有效结点  2. 销毁头结点
void DListDestroy(PDLNode* pHead);

PDLNode BuyDListNode(DataType data);
///////////////////////////////////////////////////////////

#include <stdio.h>
void DListInit(PDLNode* pHead)  // 
{
	assert(pHead);
	*pHead = BuyDListNode(0);
}

PDLNode BuyDListNode(DataType data)
{
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;

	return pNewNode;
}

void DListPushBack(PDLNode pHead, DataType data)
{
	PDLNode pCur = pHead;
	PDLNode pNewNode = NULL;
	assert(pHead);

	// 找当前链表中最后一个结点
	while(pCur->_pNext)
		pCur = pCur->_pNext;

	pNewNode = BuyDListNode(data);
	pCur->_pNext = pNewNode;
	pNewNode->_pPre = pCur;
}

void DListPopBack(PDLNode pHead)
{
	PDLNode pTailNode = pHead;
	assert(pHead);

	// 找当前链表中最后一个结点
	while(pTailNode->_pNext)
		pTailNode = pTailNode->_pNext;

	if(pTailNode != pHead)
	{
		pTailNode->_pPre->_pNext = NULL;
		free(pTailNode);
	}
}

void DListPushFront(PDLNode pHead, DataType data)
{
	PDLNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuyDListNode(data);

	pNewNode->_pNext = pHead->_pNext;
	pHead->_pNext = pNewNode;
	pNewNode->_pPre = pHead;

	// 头插时，链表中已经有节点
	if(pNewNode->_pNext)
		pNewNode->_pNext->_pPre = pNewNode;
}

void DListPopFront(PDLNode pHead)
{
	PDLNode pDelNode = NULL;
	assert(pHead);

	pDelNode = pHead->_pNext;
	// 空链表
	if(NULL == pDelNode)
		return;

	pHead->_pNext = pDelNode->_pNext;
	if(pDelNode->_pNext)
		pDelNode->_pNext->_pPre = pHead;

	free(pDelNode);
}

void DListInsert(PDLNode pos, DataType data)
{
	PDLNode pNewNode = NULL;
	if(NULL == pos || NULL == pos->_pPre)
		return;

	pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

void DListErase(PDLNode pos)
{
	// 空位置 || pos在头结点的位置
	if(NULL == pos || NULL == pos->_pPre)
		return;

	pos->_pPre->_pNext = pos->_pNext;
	
	// pos不是最后一个节点
	if(pos->_pNext)
		pos->_pNext->_pPre = pos->_pPre;
}

PDLNode DListFind(PDLNode pHead, DataType data)
{
	PDLNode pCur = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	while(pCur)
	{
		if(pCur->_data == data)
			return pCur;

		pCur = pCur->_pNext;
	}

	return NULL;
}

int DListEmpty(PDLNode pHead)
{
	assert(pHead);
	return NULL == pHead->_pNext;
}

// 链表中有效结点的个数:不包含头结点
int DListSize(PDLNode pHead)
{
	PDLNode pCur = NULL;
	int count = 0;
	assert(pHead);

	pCur = pHead->_pNext;
	while(pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

// 只清空有效结点，不删除头结点
void DListClear(PDLNode pHead)
{
	PDLNode pCur = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	while(pCur)
	{
		pHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = pHead->_pNext;
	}
}

// 1. 销毁链表中的有效结点  2. 销毁头结点
void DListDestroy(PDLNode* pHead)
{
	assert(pHead);
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

void PrintDList(PDLNode pHead)
{
	PDLNode pCur = NULL;
	PDLNode pTailNode = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	// 正向打印
	while(pCur)
	{
		printf("%d ", pCur->_data);
		pTailNode = pCur;
		pCur = pCur->_pNext;
	}
	printf("\n");

	while(pTailNode != pHead)
	{
		printf("%d ", pTailNode->_data);
		pTailNode = pTailNode->_pPre;
	}
	printf("\n");
}



void TestDList()
{
	PDLNode pHead, pos;
	DListInit(&pHead);
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);
	printf("size = %d\n", DListSize(pHead));
	PrintDList(pHead);

	DListPopBack(pHead);
	DListPopBack(pHead);
	printf("size = %d\n", DListSize(pHead));
	PrintDList(pHead);

	DListPushFront(pHead, 0);
	DListPopFront(pHead);
	printf("size = %d\n", DListSize(pHead));
	PrintDList(pHead);

	pos = DListFind(pHead, 2);
	DListInsert(pos, 4);
	printf("size = %d\n", DListSize(pHead));
	PrintDList(pHead);

	DListErase(DListFind(pHead, 4));
	printf("size = %d\n", DListSize(pHead));
	PrintDList(pHead);

	DListClear(pHead);
	printf("size = %d\n", DListSize(pHead));
	DListDestroy(&pHead);
}
