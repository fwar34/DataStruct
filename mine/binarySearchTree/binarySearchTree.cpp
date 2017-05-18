/*************************************************************************
    > File Name: binarySearchTree.cpp
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时44分14秒
    > Content: 
 ************************************************************************/
#include <iostream>
#include "binarySearchTree.h"

template<typename K>
void bstree<K>::insert(K key)
{
	if (!m_root)
	{
		m_root = new bsnode<K>();
		m_root->key = key;
		return;
	}

	bsnode<K>* x = m_root;
	bsnode<K>* y = NULL;
	while (!x)
	{
		y = x;
		if (x->key > key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	bsnode<K>* newnode = new bsnode<K>();
	newnode->key = key;

	if (y->key > key)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}
}

template<typename K>
void bstree::del(K key)
{
	if (!m_root)
	{
		return;
	}

	if (m_root->key == key)
	{
		m_root = NULL;
		return;
	}

	bsnode<K>* y = NULL;
	bsnode<K>* x = m_root;
	bsnode<K>* tmp1 = NULL;
	while (!x)
	{
		y = x;
		if (x->key > key)
		{
			x = x->left;
		}
		else if (x->key < key)
		{
			x = x->right;
		}
		else
		{
			break;
		}
	}

	bsnode<K>* tmp = NULL;
	x = y->left;
	while (!x)
	{
		tmp = x;
		x = x->right;
	}

	tmp->left = y->left;
	tmp->right = y->right;


}
