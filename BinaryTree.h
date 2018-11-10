#pragma once
#include <iostream>
#include <stack>
#include<queue>
using namespace std;

template <typename T>
struct BinaryTreeNode
{
	BinaryTreeNode(T data = T())
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
	{}
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	T _data;
};


template <typename T>
class BinaryTree
{
	typedef  BinaryTreeNode<T>  Node;

public:

	BinaryTree(const T* a, size_t size, int index, const T& invalid);
	~BinaryTree();

private:
	Node* _MakeTree(const T* a, size_t size, int& index, const T& invalid);
	void Destroy(Node* _root);
private:
	Node* _root;
};

template<typename T>
inline BinaryTree<T>::BinaryTree(const T* a, size_t size, int index, const T& invalid)
{
	_root = _MakeTree(a, size, index, invalid);
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	Destroy(_root);
}




template<typename T>
inline BinaryTreeNode<T> * BinaryTree<T>::_MakeTree(const T * a, size_t size, int & index, const T & invalid)
{
	Node *root = NULL;
	if (index < size && a[index] != invalid)
	{
		root = new Node(invalid);
		root->_data = a[index];
		root->_left = _MakeTree(a, size, ++index, invalid);
		root->_right = _MakeTree(a, size, ++index, invalid);
	}
	return root;
	return NULL;
}

template<typename T>
inline void BinaryTree<T>::Destroy(Node * _root)
{
	Node* tmp = _root;
	if (tmp == NULL)
		return;
	Destroy(tmp->_left);
	Destroy(tmp->_right);
	delete tmp;
	tmp = NULL;

}
