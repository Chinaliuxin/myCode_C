#pragma once

typedef char BTDataType;

typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft; // ����
	struct BinTreeNode* _pRight; // �Һ���
	BTDataType _data;
}BTNode, *PBTNode;

///////////////////////////////////////////////////////
//
// ����������
void CreateBinTree(PBTNode pRoot, BTDataType array[], int size);

// ����������
PBTNode CopyBinTree(PBTNode pRoot);

// ǰ�����---�ݹ�
void PreOrder(PBTNode pRoot);

// ǰ�����---�ǵݹ�
void PreOrderNor(PBTNode pRoot);

// �������---�ݹ�
void InOrder(PBTNode pRoot);

// �������---�ǵݹ�
void InOrderNor(PBTNode pRoot);

// ��������---�ݹ�
void PostOrder(PBTNode pRoot);

// ��������---�ǵݹ�
void PostOrderNor(PBTNode pRoot);

// �������
void LevelOrder(PBTNode pRoot);

// ������������
void DetroyBinTree(PBTNode* pRoot);

// �������ľ���---�ǵݹ�
void MirrorBinTreeNor(PBTNode pRoot);

// �������ľ���---�ݹ�
void MirrorBinTree(PBTNode pRoot);

// ��������н��ĸ���
int BinTreeSize(PBTNode pRoot);

// ���������Ҷ�ӽ��ĸ���
int BinTreeLeaf(PBTNode pRoot);

// ��������е�K����ĸ���
int BinTreeKLevelNode(PBTNode pRoot, int K);

// ��������ĸ߶�
int BinTreeHeight(PBTNode pRoot);

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ�
PBTNode Find(PBTNode pRoot, BTDataType data);

// ���һ���ڵ��Ƿ��ڶ�������
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// ���һ�����Ƿ�Ϊ��ȫ������
int IsCompleteBinTree(PBTNode pRoot);


////////////////////////////////////////////////////////////
// BinTree.c

#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode pNewNode = (PBTNode)malloc(sizeof(BTNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}

// A  B   D  #   #   #  C  E  #  #  F
void _CreateBinTree(PBTNode* pRoot, BTDataType array[], int size, int* index, BTDataType invalid)
{
	assert(pRoot);
	if(*index < size && invalid != array[*index])
	{
		*pRoot = BuyBinTreeNode(array[*index]);

		// �������ڵ��������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		// �������ڵ��������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}

void CreateBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

// ��+������+������
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;
	if(pRoot)
	{
		// �������ڵ�
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		// �������ڵ��������
		if(pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		// �������ڵ��������
		if(pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}

// �� + ������  +  ������
void PreOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		printf("%c   ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

void PreOrderNor(PBTNode pRoot)
{
#if 0
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);
	while(!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);

		if(pCur->_pRight)
			StackPush(&s, pCur->_pRight);

		if(pCur->_pLeft)
			StackPush(&s, pCur->_pLeft);
	}
#endif

	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);
	while(!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);
		StackPop(&s);
		while(pCur)
		{
			printf("%c ", pCur->_data);
			if(pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			pCur = pCur->_pLeft;
		}
	}
}

// ����������--->���ڵ�--->������
void InOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c   ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

void InOrderNor(PBTNode pRoot)
{
	PBTNode pCur = pRoot;
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);

	// ����pCurΪ��������ߵĽ�㣬����������·���е����нڵ�
	while(pCur || !StackEmpty(&s))
	{
		while(pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);
		pCur = pCur->_pRight;
	}
	


}

// ����������--->������--->���ڵ�
void PostOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c   ", pRoot->_data);
	}
}

void PostOrderNor(PBTNode pRoot)
{
	PBTNode pCur = pRoot, pTop;

	// ���������ʹ��Ľ��
	PBTNode pPrev = NULL;
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	while(pCur || !StackEmpty(&s))
	{
		// ������ߵĽ�㲢��������·���е����нڵ�
		while(pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pTop = StackTop(&s);
		if(NULL == pTop->_pRight || pTop->_pRight == pPrev)
		{
			printf("%c ", pTop->_data);
			pPrev = pTop;
			StackPop(&s);
		}
		else
		{
			pCur = pTop->_pRight;
		}
	}
}

void LevelOrder(PBTNode pRoot)
{
	Queue q;
	if(NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		printf("%c   ", pCur->_data);
		QueuePop(&q);

		if(pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		if(pCur->_pRight)
			QueuePush(&q, pCur->_pRight);
	}
}

void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void MirrorBinTreeNor(PBTNode pRoot)
{
	Queue q;
	if(NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		Swap(&(pCur->_pLeft), &(pCur->_pRight));

		if(pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		if(pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}
}

void MirrorBinTree(PBTNode pRoot)
{
	if(pRoot)
	{
		Swap(&(pRoot->_pLeft), &(pRoot->_pRight));
		MirrorBinTree(pRoot->_pLeft);
		MirrorBinTree(pRoot->_pRight);
	}
}

void DetroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if(*pRoot)
	{
		// ����������
		DetroyBinTree(&(*pRoot)->_pLeft);

		// ����������
		DetroyBinTree(&(*pRoot)->_pRight);

		// ���ٸ��ڵ�
		free(*pRoot);
		*pRoot = NULL;
	}
}

int BinTreeSize(PBTNode pRoot)
{
	if(NULL == pRoot)
		return 0;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}

int BinTreeLeaf(PBTNode pRoot)
{
	if(NULL == pRoot)
		return 0;

	if(NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return BinTreeLeaf(pRoot->_pLeft) + BinTreeLeaf(pRoot->_pRight);
}

int BinTreeKLevelNode(PBTNode pRoot, int K)
{
	if(NULL == pRoot || K <= 0)
		return 0;

	if(1 == K)
		return 1;

	return BinTreeKLevelNode(pRoot->_pLeft, K-1) + BinTreeKLevelNode(pRoot->_pRight, K-1);
}

int count = 0;
int BinTreeHeight(PBTNode pRoot)
{
	int leftHeight = 0, rightHeight = 0;
	count++;
	if(NULL == pRoot)
		return 0;

	if(NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	leftHeight = BinTreeHeight(pRoot->_pLeft);
	rightHeight = BinTreeHeight(pRoot->_pRight);

	return leftHeight>rightHeight? (leftHeight+1):(rightHeight+1);
}

PBTNode Find(PBTNode pRoot, BTDataType data)
{
	PBTNode pNode = NULL;
	if(NULL == pRoot)
		return NULL;

	if(data == pRoot->_data)
		return pRoot;

	if(pNode = Find(pRoot->_pLeft, data))
		return pNode;

	return Find(pRoot->_pRight, data);
}

int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode)
{
	if(NULL == pRoot || NULL == pNode)
		return 0;

	if(pRoot == pNode)
		return 1;

	if(IsNodeInBinTree(pRoot->_pLeft, pNode))
		return 1;

	return IsNodeInBinTree(pRoot->_pRight, pNode);
}

int IsCompleteBinTree(PBTNode pRoot)
{
	Queue q;
	int flag = 0;
	if(NULL == pRoot)
		return 1;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		if(flag)
		{
			if(pCur->_pLeft || pCur->_pRight)
				return 0;
		}
		else
		{
			if(pCur->_pLeft && pCur->_pRight)
			{
				QueuePush(&q, pRoot->_pLeft);
				QueuePush(&q, pRoot->_pRight);
			}
			else if(pCur->_pRight)
				return 0;
			else if(pCur->_pLeft)
			{
				QueuePush(&q, pRoot->_pLeft);
				flag = 1;
			}
			else
				flag = 1;

			QueuePop(&q);
		}
	     

	return 1;
}

	void TestBinTree();
void TestBinTree()
{
	
	char* str = "ABD###CE##F";
	PBTNode pRoot = NULL, pNewRoot;
	PBTNode pNode = NULL;
	int IsComBinTree = 0;
	CreateBinTree(&pRoot, str, strlen(str), '#');
	pNewRoot = CopyBinTree(pRoot);

	//
	printf("ǰ�������");
	PreOrder(pRoot);
	printf("\n");
	PreOrderNor(pRoot);
	printf("\n");


	printf("���������");
	InOrder(pRoot);
	printf("\n");
	InOrderNor(pRoot);
	printf("\n");

	printf("���������");
	PostOrder(pRoot);
	printf("\n");
	PostOrderNor(pRoot);
	printf("\n");

	printf("���������");
	LevelOrder(pRoot);
	printf("\n");

	MirrorBinTree(pRoot);
	MirrorBinTreeNor(pRoot);

	printf("���������");
	LevelOrder(pRoot);
	printf("\n");

	printf("�������н��ĸ���Ϊ��%d\n", BinTreeSize(pRoot));
	printf("��������Ҷ�ӽ��ĸ���Ϊ��%d\n", BinTreeLeaf(pRoot));
	printf("��������3����ĸ���Ϊ��%d\n", BinTreeKLevelNode(pRoot, 3));
	printf("�������ĸ߶ȣ�%d\n", BinTreeHeight(pRoot));

	PBTNode pNode = Find(pRoot, 'E');
	if(IsNodeInBinTree(pRoot, pNode))
		printf("%c �ڶ�������\n", pNode->_data);
	else
		printf("E �ڶ�������\n");

	if(IsCompleteBinTree(pRoot))
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");
}