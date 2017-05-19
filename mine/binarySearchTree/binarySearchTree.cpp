/*************************************************************************
    > File Name: binarySearchTree.cpp
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时44分14秒
    > Content: bstree
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
	while (x)
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
	if (!tree)
	{
		return;
	}

	bsnode<K>* x = tree;
	bsnode<K>* y = NULL;
	bsnode<K>* z = NULL;

	//这个while执行完成后x就指向了与key相等的节点
	//y就指向了x的父节点（如果x是root节点则y就为空）
	while (x && x->key != key)
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

	//要删除的节点有两个孩子节点
	if (x->left && x->right)
	{
		bsnode<K>* x1 = x->left;
		bsnode<K>* y1 = x;
		//这个while执行完成后x1就指向了x的左子树的最大节点
		//y就指向了x1的父节点
		while (x1 && x1->right)
		{
			y1 = x1;
			x1 = x1->right;
		}

		y1->right = NULL;
		x1->left = x->left;
		x1->right = x->right;

		//要删除的是root节点
		if (!y)
		{
			m_root = x1;
		}
		else
		{
			if (x = y->left)
			{
				y->left = x1;
			}
			else
			{
				y->right = x1;
			}
		}

		delete x;
	}
	//要删除的节点只有一个子节点
	else if (x->left || x->right)
	{
		if (x->left)
		{
			z = x->left;
		}
		else
		{
			z = x->right;
		}

		//要删除的是root节点
		if (!y)
		{
			m_root = z;
		}
		else
		{
			if (x = y->left)
			{
				y->left = z;
			}
			else
			{
				y->right = z;
			}
		}
		
		delete x;
	}
	//要删除的节点是个叶子节点
	else
	{
		//要删除的是root节点
		if (!y)
		{
			m_root = NULL;
		}
		else
		{
			if (x == y->left)
			{
				y->left = NULL;
			}
			else
			{
				y->right = NULL;
			}
		}
		
		delete x;
	}
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
		return search(tree->left, key);
	}
	else
	{
		return search(tree->right, key);
	}
}

template <typename K>
bool bstree<K>::contains(K key)
{
	if (search(key))
	{
		return true;
	}
	return false;
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
}

template <typename K>
K& bstree<K>::max()
{
	bsnode<K>* ret = max(m_root);
	if (ret)
	{
		return ret->key;
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
