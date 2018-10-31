#pragma once

typedef char BTDataType;

typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft; // 左孩子
	struct BinTreeNode* _pRight; // 右孩子
	BTDataType _data;
}BTNode, *PBTNode;

///////////////////////////////////////////////////////
//
// 二叉树创建
void CreateBinTree(PBTNode pRoot, BTDataType array[], int size);

// 二叉树拷贝
PBTNode CopyBinTree(PBTNode pRoot);

// 前序遍历---递归
void PreOrder(PBTNode pRoot);

// 前序遍历---非递归
void PreOrderNor(PBTNode pRoot);

// 中序遍历---递归
void InOrder(PBTNode pRoot);

// 中序遍历---非递归
void InOrderNor(PBTNode pRoot);

// 后续遍历---递归
void PostOrder(PBTNode pRoot);

// 后续遍历---非递归
void PostOrderNor(PBTNode pRoot);

// 层序遍历
void LevelOrder(PBTNode pRoot);

// 二叉树的销毁
void DetroyBinTree(PBTNode* pRoot);

// 二叉树的镜像---非递归
void MirrorBinTreeNor(PBTNode pRoot);

// 二叉树的镜像---递归
void MirrorBinTree(PBTNode pRoot);

// 求二叉树中结点的个数
int BinTreeSize(PBTNode pRoot);

// 求二叉树中叶子结点的个数
int BinTreeLeaf(PBTNode pRoot);

// 求二叉树中第K层结点的个数
int BinTreeKLevelNode(PBTNode pRoot, int K);

// 求二叉树的高度
int BinTreeHeight(PBTNode pRoot);

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空
PBTNode Find(PBTNode pRoot, BTDataType data);

// 检测一个节点是否在二叉树中
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// 检测一棵树是否为完全二叉树
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

		// 创建根节点的左子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		// 创建根节点的右子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}

void CreateBinTree(PBTNode* pRoot, BTDataType array[], int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

// 根+左子树+右子树
PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;
	if(pRoot)
	{
		// 拷贝根节点
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		// 拷贝根节点的左子树
		if(pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		// 拷贝根节点的右子树
		if(pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}

// 根 + 左子树  +  右子树
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

// 中序：左子树--->根节点--->右子树
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

	// 找以pCur为根树最左边的结点，并保存所经路径中的所有节点
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

// 中序：左子树--->右子树--->根节点
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

	// 标记最近访问过的结点
	PBTNode pPrev = NULL;
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	while(pCur || !StackEmpty(&s))
	{
		// 找最左边的结点并保存所经路径中的所有节点
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
		// 销毁左子树
		DetroyBinTree(&(*pRoot)->_pLeft);

		// 销毁右子树
		DetroyBinTree(&(*pRoot)->_pRight);

		// 销毁根节点
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
	printf("前序遍历：");
	PreOrder(pRoot);
	printf("\n");
	PreOrderNor(pRoot);
	printf("\n");


	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");
	InOrderNor(pRoot);
	printf("\n");

	printf("后序遍历：");
	PostOrder(pRoot);
	printf("\n");
	PostOrderNor(pRoot);
	printf("\n");

	printf("层序遍历：");
	LevelOrder(pRoot);
	printf("\n");

	MirrorBinTree(pRoot);
	MirrorBinTreeNor(pRoot);

	printf("层序遍历：");
	LevelOrder(pRoot);
	printf("\n");

	printf("二叉树中结点的个数为：%d\n", BinTreeSize(pRoot));
	printf("二叉树中叶子结点的个数为：%d\n", BinTreeLeaf(pRoot));
	printf("二叉树第3层结点的个数为：%d\n", BinTreeKLevelNode(pRoot, 3));
	printf("二叉树的高度：%d\n", BinTreeHeight(pRoot));

	PBTNode pNode = Find(pRoot, 'E');
	if(IsNodeInBinTree(pRoot, pNode))
		printf("%c 在二叉树中\n", pNode->_data);
	else
		printf("E 在二叉树中\n");

	if(IsCompleteBinTree(pRoot))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");
}