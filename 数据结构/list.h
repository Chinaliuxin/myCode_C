#pragma once


typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;


//////////////////不带头结点的单链表//////////////////////////////////////
// .h
void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead, DataType data);
void SListPopBack(PNode* pHead);
void SListPushFront(PNode* pHead, DataType data);
void SListPopFront(PNode* pHead);
PNode SListFind(PNode pHead, DataType data);
void SListInsert(PNode* pHead, PNode pos, DataType data);
void SListErase(PNode* pHead, PNode pos);
void SListDestroy(PNode* pHead);
int SListSize(PNode pHead);
void SListClear(PNode* pHead);
PNode BuySListNode(DataType data);
PNode SListBack(PNode pHead);

//////////////////////////////////////////////////////////
void DeleteNotTailNode(PNode pos);
void InsertPosFront(PNode pos, DataType data);
void JosephCircle(PNode* pHead, const int M);
void BubbleSort(PNode pHead);
void ReverseSList(PNode* pHead);
PNode ReverseSListOP(PNode pHead);
PNode MergeSList(PNode pHead1, PNode pHead2);
PNode FindMiddleNode(PNode pHead);
PNode FindLastKNode(PNode pHead, int K);
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);
PNode GetCrossNode(PNode pHead1, PNode pHead2);

PNode IsCircle(PNode pHead);
int GetCircleLen(PNode pHead);
PNode GetEnterNode(PNode pHead, PNode pMeetNode);
int IsListCrossWithCircle(PNode pHead1, PNode pHead2);
/////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

void SListPushBack(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuySListNode(data);
	// 空
	if(NULL == *pHead)
		*pHead = pNewNode;
	else
	{
		// 非空
		PNode pCur = *pHead;
		while(pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(PNode* pHead)
{
	assert(pHead);
	//空
	if(NULL == *pHead)
		return;
	else if(NULL == (*pHead)->_pNext)
	{
		// 只有一个节点
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		// 多个结点 1--->2--->NULL
		PNode pCur = *pHead;
		while(pCur->_pNext->_pNext)
			pCur = pCur->_pNext;

		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}

void SListPushFront(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	pNewNode = BuySListNode(data);
	if(NULL == pNewNode)
		return;

	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}

void SListPopFront(PNode* pHead)
{
	PNode pDelNode = NULL;
	assert(pHead);
	if(NULL == *pHead)
		return;

	pDelNode = *pHead;
	*pHead = pDelNode->_pNext;
	free(pDelNode);
}

PNode SListFind(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while(pCur)
	{
		if(data == pCur->_data)
			return pCur;

		pCur = pCur->_pNext;
	}

	return NULL;
}


void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
		return;

	pNewNode = BuySListNode(data);
	if(NULL == pNewNode)
		return;

	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(PNode* pHead, PNode pos)
{
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
		return;

	if(pos == *pHead)
		SListPopFront(pHead);
	else
	{
		PNode pCur = *pHead;
		while(pCur && pCur->_pNext != pos)
			pCur = pCur->_pNext;

		if(pCur)
		{
			pCur->_pNext = pos->_pNext;
			free(pos);
		}
	}
}

void SListDestroy(PNode* pHead)
{
	SListClear(pHead);
}

int SListSize(PNode pHead)
{
	int count = 0;
	PNode pCur = pHead;
	while(pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

void SListClear(PNode* pHead)
{
	PNode pDelNode = NULL;
	assert(pHead);

	while(*pHead)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

PNode BuySListNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
		return NULL;

	pNewNode->_pNext = NULL;
	pNewNode->_data = data;

	return pNewNode;
}

// 找链表中最后一个节点的位置
PNode SListBack(PNode pHead)
{
	PNode pCur = pHead;
	if(NULL == pHead)
		return NULL;

	while(pCur->_pNext)
		pCur = pCur->_pNext;

	return pCur;
}

void PrintList(PNode pHead)
{
	PNode pCur = pHead;
	while(pCur)
	{
		printf("%d---->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}

///////////////////////////////////////////////////////////

void PrintListFromTail2Head(PNode pHead)
{
	if(pHead)
	{
		PrintListFromTail2Head(pHead->_pNext);
		printf("%d ", pHead->_data);
	}
}

void DeleteNotTailNode(PNode pos)
{
	PNode pDelNode = NULL;
	if(NULL == pos && NULL == pos->_pNext)
		return;

	pDelNode = pos->_pNext;
	pos->_data = pDelNode->_data;
	pos->_pNext = pDelNode->_pNext;
	free(pDelNode);
}

void InsertPosFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if(NULL == pos)
		return;

	pNewNode = BuySListNode(pos->_data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	pos->_data = data;
}

//
void JosephCircle(PNode* pHead, const int M)
{
	PNode pCur = NULL;
	PNode pDelNode = NULL;
	assert(pHead);
	if(NULL == *pHead)
		return;

	pCur = *pHead;
	while(pCur != pCur->_pNext)
	{
		// 报数
		int count = M;
		while(--count)
			pCur = pCur->_pNext;

		// 删结点--替换法删除
		pDelNode = pCur->_pNext;
		pCur->_data = pDelNode->_data;
		pCur->_pNext = pDelNode->_pNext;
		free(pDelNode);
	}

	*pHead = pCur;
}

void BubbleSort(PNode pHead)
{
	PNode pPreCur = NULL;
	PNode pCur = NULL;
	PNode pTail = NULL;
	
	if(NULL == pHead || NULL == pHead->_pNext)
		return;

	while(pHead != pTail)
	{
		int IsChange = 0;
		pPreCur = pHead;
		pCur = pPreCur->_pNext;
		while(pCur != pTail)
		{
			if(pPreCur->_data > pCur->_data)
			{
				int temp = pPreCur->_data;
				pPreCur->_data = pCur->_data;
				pCur->_data = temp;
				IsChange = 1;
			}

			pPreCur = pCur;
			pCur = pPreCur->_pNext;
		}

		if(!IsChange)
			return;

		pTail = pPreCur;
	}
}

// 三个指针
void ReverseSList(PNode* pHead)
{
	PNode pPre = NULL, pCur = NULL, pNext = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == (*pHead)->_pNext)
		return;

	pCur = *pHead;
	while(pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}

	*pHead = pPre;
}

// 头插法--
PNode ReverseSListOP(PNode pHead)
{
	PNode pNewHead = NULL;
	PNode pCur = NULL;
	PNode pNext = NULL;

	pCur = pHead;
	while(pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pNewHead;
		pNewHead = pCur;
		pCur = pNext;
	}

	return pNewHead;
}

PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pNewHead = NULL;
	PNode pTailNode = NULL;
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;

	if(NULL == pHead1)
		return pHead2;

	if(NULL == pHead2)
		return pHead1;

	// 两个链表都不为空
	if(pL1->_data < pL2->_data)
	{
		pNewHead = pL1;
		pL1 = pL1->_pNext;
	}
	else
	{
		pNewHead = pL2;
		pL2 = pL2->_pNext;
	}

	pTailNode = pNewHead;

	while(pL1 && pL2)
	{
		if(pL1->_data < pL2->_data)
		{
			pTailNode->_pNext = pL1;
			pL1 = pL1->_pNext;
		}
		else
		{
			pTailNode->_pNext = pL2;
			pL2 = pL2->_pNext;
		}

		pTailNode = pTailNode->_pNext;
	}

	if(pL1)
		pTailNode->_pNext = pL1;
	else
		pTailNode->_pNext = pL2;

	return pNewHead;
}

// 快慢指针---快 走2步  慢 走1步
PNode FindMiddleNode(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}

	return pSlow;
}

PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if(NULL == pHead || K <= 0)
		return NULL;


	// 让pFast先走K步（K-1）
	while(K--)
	{
		// K大于链表中结点的个数
		if(NULL == pFast)
			return NULL;

		pFast = pFast->_pNext;
	}

	// 让两个指针同时超后走,每次走一步
	while(pFast)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}

	return pSlow;
}

int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	PNode pTail1 = pHead1;
	PNode pTail2 = pHead2;

	if(NULL == pHead1 || NULL == pHead2)
		return 0;

	// 找第一个链表的最后一个节点
	while(pTail1->_pNext)
		pTail1 = pTail1->_pNext;

	// 找第二个链表的最后一个节点
	while(pTail2->_pNext)
		pTail2 = pTail2->_pNext;

	return pTail1 == pTail2;
}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0, size2 = 0, gap;
	PNode pCur1 = pHead1, pCur2 = pHead2;
	if(!IsCrossWithoutCircle(pHead1, pHead2))
		return NULL;

	// 求两个链表中结点的个数
	while(pCur1)
	{
		size1++;
		pCur1 = pCur1->_pNext;
	}

	while(pCur2)
	{
		size2++;
		pCur2 = pCur2->_pNext;
	}

	// 让长的链表先朝后走差值步
	gap = size1 - size2;
	pCur1 = pHead1;
	pCur2 = pHead2;
	if(gap > 0)
	{
		while(gap--)
			pCur1 = pCur1->_pNext;
	}
	else
	{
		while(gap++)
			pCur2 = pCur2->_pNext;
	}

	while(pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}

	return pCur1;
}

PNode IsCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;

		if(pFast == pSlow)
			return pFast;
	}

	return NULL;
}

int GetCircleLen(PNode pHead)
{  
	PNode pMeetNode = IsCircle(pHead);
	PNode pCur = pMeetNode;
	int count = 1;

	if(NULL == pMeetNode)
		return 0;

	while(pCur->_pNext != pMeetNode)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;
	PNode pM = pMeetNode;
	if(NULL == pHead || NULL == pMeetNode)
		return NULL;

	while(pH != pM)
	{
		pH = pH->_pNext;
		pM = pM->_pNext;
	}

	return pM;
}

int IsListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = NULL, pMeetNode2 = NULL;
	if(NULL == pHead1 || NULL == pHead2)
		return 0;

	pMeetNode1 = IsCircle(pHead1);
	pMeetNode2 = IsCircle(pHead2);
	
	// 两个链表都不带环
	if(NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		// 找两个链表的最后一个节点，然后检测是否是同一个节点
		PNode pTail1 = pHead1;
		PNode pTail2 = pHead2;
		while(pTail1->_pNext)
			pTail1 = pTail1->_pNext;

		while(pTail2->_pNext)
			pTail2 = pTail2->_pNext;

		if(pTail1 == pTail2)
			return 1;
	}
	else if(pMeetNode1 && pMeetNode2)
	{
		// 两个链表均带环
		PNode pCur = pMeetNode1;
		
		do
		{
			if(pCur == pMeetNode2)
				return 2;

			pCur = pCur->_pNext;

		}while(pCur != pMeetNode1);
	}

	return 0;
}



typedef struct ComplexListNode
{
	struct ComplexListNode* _pNext;
	struct ComplexListNode* _pRandom;  // 可以指向链表中的任意结点，包括自己和NULL
	DataType _data;
}ComplexListNode, *PComplexListNode;

PComplexListNode CopyComplexList(PComplexListNode pHead)
{
	PComplexListNode pOldNode = pHead;
	PComplexListNode pNewNode = NULL;
	PComplexListNode pNewHead = NULL;

	if(NULL == pHead)
		return NULL;

	// 在原链表每个结点后插入值相同的新节点
	while(pOldNode)
	{
		pNewNode = (PComplexListNode)malloc(sizeof(ComplexListNode));
		if(NULL == pNewNode)
			return NULL;

		pNewNode->_data = pOldNode->_data;
		pNewNode->_pNext = NULL;
		pNewNode->_pRandom = NULL;

		pNewNode->_pNext = pOldNode->_pNext;
		pOldNode->_pNext = pNewNode;
		pOldNode = pNewNode->_pNext;
	}

	// 给新插入结点的随机指针域赋值
	pOldNode = pHead;
	while(pOldNode)
	{
		pNewNode = pOldNode->_pNext;
		if(NULL == pOldNode->_pRandom)
			pNewNode->_pRandom = NULL;
		else
			pNewNode->_pRandom = pOldNode->_pRandom->_pNext;

		pOldNode = pNewNode->_pNext;
	}

	// 将新插入的结点从原链表中拆开
	pOldNode = pHead;
	pNewHead = pOldNode->_pNext;
	while(pOldNode->_pNext)
	{
		pNewNode = pOldNode->_pNext;
		pOldNode->_pNext = pNewNode->_pNext;
		pOldNode = pNewNode;
	}

	return pNewHead;
}

void TestComplexList()
{
	ComplexListNode node1, node2, node3, node4;
	PComplexListNode pHead = NULL;
	node1._data = 1;
	node1._pNext = &node2;
	node1._pRandom = &node3;

	node2._data = 2;
	node2._pNext = &node3;
	node2._pRandom = &node1;

	node3._data = 3;
	node3._pNext = &node4;
	node3._pRandom = &node3;

	node4._data = 4;
	node4._pNext = NULL;
	node4._pRandom = NULL;

	pHead = CopyComplexList(&node1);
}


// SListPushBack/SListPopBack
void TestSList1()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintList(pHead);

	SListPopBack(&pHead);
	PrintList(pHead);

	SListPopBack(&pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	PrintList(pHead);

	SListPopBack(&pHead);
}

// SListPushFront/SListPopFront
void TestSList2()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushFront(&pHead, 1);
	SListPushFront(&pHead, 2);
	SListPushFront(&pHead, 3);
	SListPushFront(&pHead, 4);
	SListPushFront(&pHead, 5);
	PrintList(pHead);

	SListPopFront(&pHead);
	PrintList(pHead);

	SListPopFront(&pHead);
	SListPopFront(&pHead);
	SListPopFront(&pHead);
	PrintList(pHead);
}

// PrintListFromTail2Head
void TestSList3()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushFront(&pHead, 1);
	SListPushFront(&pHead, 2);
	SListPushFront(&pHead, 3);
	SListPushFront(&pHead, 4);
	SListPushFront(&pHead, 5);
	PrintList(pHead);
	PrintListFromTail2Head(pHead);
}

// SListInsert/SListErase
void TestSList4()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintList(pHead);

	pos = SListFind(pHead, 3);
	if(pos)
		SListInsert(&pHead, pos, 6);

	PrintList(pHead);

	SListErase(&pHead, pos);
	PrintList(pHead);

	printf("size = %d\n", SListSize(pHead));

	SListClear(&pHead);
	printf("size = %d\n", SListSize(pHead));
	SListDestroy(&pHead);
}

void TestJosephCircle()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	PrintList(pHead);

	// 构环
	SListBack(pHead)->_pNext = pHead;
	JosephCircle(&pHead, 3);
	
	// 解环
	pHead->_pNext = NULL;
}

void TestSListBubbleSort()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 2);
	PrintList(pHead);

	BubbleSort(pHead);
	PrintList(pHead);
	SListDestroy(&pHead);
}

void TestReverseList()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintList(pHead);

	//ReverseSList(&pHead);
	pHead = ReverseSListOP(pHead);
	PrintList(pHead);
}

void TestMergeSList()
{
	PNode pHead1, pHead2;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);
	PrintList(pHead1);

	SListInit(&pHead2);
	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 8);
	PrintList(pHead2);

	pHead1 = MergeSList(pHead1, pHead2);
	PrintList(pHead1);
	SListDestroy(&pHead1);
}

void TestFindMidAndLastKNode()
{
	PNode pHead, pCur = NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintList(pHead);
#if 0
	pCur = FindMiddleNode(pHead);
	printf("中间结点是:%d\n", pCur->_data);

	SListPopBack(&pHead);

	pCur = FindMiddleNode(pHead);
	printf("中间结点是:%d\n", pCur->_data);
#else
	pCur = FindLastKNode(pHead, 2);
	if(pCur)
		printf("链表中倒数第%d个结点是:%d\n", 2, pCur->_data);
	else
		printf("链表中倒数第%d个结点不存在\n", 2);

	pCur = FindLastKNode(pHead, 100);
	if(pCur)
		printf("链表中倒数第%d个结点是:%d\n", 100, pCur->_data);
	else
		printf("链表中倒数第%d个结点不存在\n", 100);
#endif
	SListDestroy(&pHead);
}

void TestIsSListCross()
{
	// 相交
	// 不相交
	PNode pHead1 = NULL, pHead2 = NULL, pCur;
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);

	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 7);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 9);
	SListPushBack(&pHead2, 0);

	SListBack(pHead1)->_pNext = SListFind(pHead2, 8);
	if (IsCrossWithoutCircle(pHead1, pHead2))
	{
		printf("两个链表相交\n");
		pCur = GetCrossNode(pHead1, pHead2);
		assert(pCur);
		printf("交点为：%d\n", pCur->_data);
	}
	else
		printf("两个链表不相交\n");
}

void TestIsListCrossWithCircle()
{
	PNode pHead1 = NULL, pHead2 = NULL, pCur;
	int ret = 0;

	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 8);
	SListBack(pHead1)->_pNext = SListFind(pHead1, 5);


	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 3);
	SListBack(pHead2)->_pNext = SListFind(pHead1, 3);

	ret = IsListCrossWithCircle(pHead1, pHead2);
	if(1 == ret)
		printf("两个链表不带环相交\n");
	else if(2 == ret)
		printf("两个链表均带环相交\n");
	else
		printf("两个链表不相交\n");

}