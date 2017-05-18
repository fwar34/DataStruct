/*************************************************************************
    > File Name: binarySearchTree.cpp
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时44分14秒
    > Content: 
 ************************************************************************/
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

template <typename K>
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

template <typename K>
void bstree<K>::insert_r(K key)
{
	insert_r(m_root, key);
}

template <typename K>
void bstree<K>::insert_r(bsnode<K>*& tree, K key)
{
	if (!tree)
	{
		tree = new bsnode<K>();
		tree->key = key;
		return;
	}

	if (tree->key > key)
	{
		insert_r(tree->left, key);
	}
	else if (tree->key < key)
	{
		insert_r(tree->right, key);
	}
}

template <typename K>
void bstree<K>::remove(K key)
{
	remove(m_root, key);
}

template <typename K>
void bstree<K>::remove(bsnode<K>* tree, K key)
{
	
}

template <typename K>
bsnode<K>* bstree<K>::search(K key)
{
	return search(m_root, key);
}

template <typename K>
void bstree<K>::ptree()
{
	ptree(m_root);
}

template <typename K>
bsnode<K>* bstree::search(bsnode<K>* tree, K key)
{
	if (!tree)
	{
		return NULL;
	}

	if (tree->key == key)
	{
		return tree;
	}
	else if (tree->key > key)
	{
		return search(tree->left);
	}
	else
	{
		return search(tree->right);
	}
}

template <typename K>
void bstree<K>::ptree(bsnode<K>* tree)
{
	if (!tree)
	{
		return;
	}

	ptree(tree->left);
	cout << tree->key << endl;
	ptree(tree->right);
}

template <typename K>
K& bstree<K>::min()
{
	bsnode<K>* ret = min(m_root);
	if (ret)
	{
		return ret->key;
	}
	else
	{
		
	}
}

template <typename K>
K& bstree<K>::max()
{
	bsnode<K>* ret = max(m_root);
	if (ret)
	{
		return ret->key;
	}
	else
	{

	}
}

template<typename K>
bsnode<K>* bstree<K>::min(bsnode<K>* tree)
{
	if (!tree)
	{
		return NULL;
	}

	if (!tree->left)
	{
		return tree;
	}

	return min(tree->left);
}

template<typename K>
bsnode<K>* bstree<K>::max(bsnode<K>* tree)
{
	if (tree)
	{
		while (tree->right)
		{
			tree = tree->right;
		}
	}	

	return tree;
}
