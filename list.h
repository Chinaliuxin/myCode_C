
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
	bool add(T);//��ӽڵ�
	bool remove(int);//ɾ���ڵ�
	T getValue(int);//���ĳ�ڵ��ֵ
	int getIndex(T);//��ȡĳ�ڵ������
	int getLength();//��ȡ����ĳ���
	Node<T>* getHead();//��ȡ�����ͷָ��
	bool addnode(int, T);//���ӽڵ���Ϣ ���뵽��int��֮��
	~LinkList();//�ͷ�����
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
			printf("����Ԥ�ϵ�վ��λ��\n");
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

