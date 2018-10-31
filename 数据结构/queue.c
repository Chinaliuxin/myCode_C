#include "Queue.h"
#include <assert.h>
#include <malloc.h>

#define  NULL 0

PNode BuyNode(QDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}

void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	if(NULL == q->_pHead)
	{ 
		q->_pHead = q->_pTail = BuyNode(data);
	}
	else
	{
	//	q->_pTail->_pNext = BuyNode(data);
		(*(*q)._pTail)._pNext = BuyNode(data);
		q->_pTail = q->_pTail->_pNext;
	}
}

void QueuePop(Queue* q)
{
	PNode pDelNode = q->_pHead;
//	Node* tmpNode = (*q)._pHead;
	if(pDelNode)
	{
	//	q->_pHead = pDelNode->_pNext;
		q->_pHead = q->_pHead->_pNext;
		free(pDelNode);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_pTail->_data;
}

int QueueSize(Queue* q)
{
	int count = 0;
	PNode pCur = q->_pHead;
	while(pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}

	return count;
}

int QueueEmpty(Queue* q)
{
	return NULL == q->_pHead;
}