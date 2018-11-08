
#ifndef LinkList_HH
#define LinkList_HH
#include<stdlib.h>
#include <stdio.h>
template <typename T>


struct Node
{
	T value;
	 Node *next;
};


template <typename T>
class LinkList
{
private:
	int Length;
	Node<T> *head;
public:
	LinkList();
	bool add(T);//添加节点
	bool remove(int);//删除节点
	T getValue(int);//获得某节点的值
	int getIndex(T);//获取某节点的索引
	int getLength();//获取链表的长度
	Node<T>* getHead();//获取链表的头指针
	bool addnode(int, T);//增加节点信息 插入到第int个之后
	~LinkList();//释放链表
};


template <typename T>
LinkList<T>::LinkList()
{
	head = (new Node<T>());
	Length = -1;
	head->next = NULL;
}


template <typename T>
bool LinkList<T>::add(T value)
{
	try {
		if (Length == -1)
		{
			head->value = value;
			head->next = NULL;
			Length = 0;
			return true;
		}

		Node<T> *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		Node<T> *node = new Node<T>();
		node->value = value;
		node->next = NULL;
		temp->next = node;
	return true;
	}
	catch (...) {}
	return false;
}
template <typename T>
bool LinkList<T>::remove(int index)
{
	if (index > Length || index < 0)
	{
		return false;
	}

	Node<T> *aTemp = head;
	Node<T> *pTemp = NULL;
	int count = 0;
	while (count <= Length)
	{
		if (count == index && index == 0)
		{
			head = aTemp->next;
			free(aTemp);
			aTemp = NULL;
			Length--;
			break;
		}
		if (count == index)
		{
			pTemp->next = aTemp->next;
			free(aTemp);
			Length--;
			aTemp = NULL;
			break;
		}
		pTemp = aTemp;
		aTemp = aTemp->next;
		count++;
	}
	return true;
}
template <typename T>


bool LinkList<T>::addnode(int index, T value)
{
	try {
		if (index == Length)
		{
			add(value);
			return true;
		}
		else if (index<0 || index>Length)
		{
			printf("不可预料的站点位置\n");
			return false;
		}
		int count = 0;
		Node<T> *temp = head;
		while (count < index)
		{
			temp = temp->next;
			count++;
		}
		Node<T> *node = new Node<T>();
		node->value = value;
		node->next = temp->next;
		temp->next = node;
		++Length;
		return true;
	}
	catch (...) {}
	return false;
}
template <typename T>
int LinkList<T>::getLength()
{
	return Length + 1;
}
template <typename T>


Node<T>* LinkList<T>::getHead()
{
	return head;
}
template <typename T>
T LinkList<T>::getValue(int index)
{
	if (index < 0 || index > Length)
	{
		return NULL;
	}
	Node<T> * temp = head;
	int count = 0;
	while (count <= Length)
	{
		if (count == index)
		{
			return temp->value;
		}
		temp = temp->next;
		count++;
	}
	return NULL;
}
template <typename T>
int LinkList<T>::getIndex(T value)
{
	if (Length == -1)
	{
		return -1;
	}
	Node<T> *temp = head;
	int count = 0;
	while (count <= Length)
	{
		T v = temp->value;
		if (v == value)
		{
			return count;
		}
		temp = temp->next;
		count++;
	}
	return -1;
}
template <typename T>
LinkList<T>::~LinkList()
{
	Node<T> *temp = head;
	Node<T> *temp1 = NULL;
	int count = 0;
	while (count <= Length)
	{
		temp1 = temp;
		if (temp1 != NULL)
		{
			temp = temp->next;
			free(temp1);
			temp1 = NULL;
		}
		count++;
	}
}
#endif

