#pragma once
#include "BinaryTree.h"
//typedef int DataType;
extern struct BTNode;
typedef  PBTNode  QDataType;

typedef struct Node
{
	QDataType _data;
	struct Node* _pNext;
}Node, *PNode;

typedef struct Queue
{
	Node * _pHead;//front
	PNode _pTail;//back
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);