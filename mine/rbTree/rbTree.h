/*************************************************************************
    > File Name: rbTree.h
    > Author: Feng
    > Created Time: 2017年05月27日 星期六 15时20分40秒
    > Content: rbTree
 ************************************************************************/

#pragma once

#include <iostream>
#include <algorithm>

enum rbcolor
{
	RED,
	BLACK
};

template <typename K>
struct rbnode
{
	rbnode* parent;
	rbnode* left;
	rbnode* right;
	rbcolor color;
	K key;
	rbnode(K k) : parent(NULL), left(NULL), right(NULL), color(RED), key(k)
	{
	}
};

template <typename K>
class rbtree
{
private:
	rbnode<K>* m_root;
	size_t m_size;

public:
	rbtree() : m_root(NULL), m_size(0)
	{
	}
	void insert(K key);
	void remove(K key);

private:
	rbnode<K>* grandparent(rbnode<K>* node);
	rbnode<K>* uncle(rbnode<K>* node);
	void llrotate(rbnode<K>* node);
	void rrrotate(rbnode<K>* node);
};

template <typename K>
rbnode<K>* rbtree<K>::grandparent(rbnode<K>* node)
{
	return node->parent->parent;
}

template <typename K>
rbnode<K>* rbtree<K>::uncle(rbnode<K>* node)
{
	if (grandparent(node)->left == node->parent)
	{
		return grandparent(node)->right;
	}
	else
	{
		return grandparent(node)->left;
	}
}

template <typename K>
void rbtree<K>::llrotate(rbnode<K>* node)
{
	rbnode<K>* x = node->left;
	node->left = x->right;
	node->left->parent = node;
	x->right = node;
	if (node == m_root)
	{
		m_root == x;
		x->parent = NULL;
	}
	else
	{
		x->parent = node->parent;
	}
	node->parent = x;
}

template <typename K>
void rbtree<K>::rrrotate(rbnode<K>* node)
{
	rbnode<K>* x = node->right;
	node->right = x->left;
	node->right->parent = node;
	x->left = node;
	if (node == m_root)
	{
		m_root = x;
		x->parent = NULL;
	}
	else
	{
		x->parent = node->parent;
	}
	node->parent = x;
}

template <typename K>
void rbtree<K>::insert(K key)
{
	rbnode<K>* dest = m_root;
	rbnode<K>* parentdest = NULL;
	while (dest && dest->key != key)
	{
		parentdest = dest;
		if (dest->key > key)
		{
			dest = dest->left;
		}
		else
		{
			dest = dest->right;
		}
	}

	if (!parentdest)
	{
		m_root = new rbnode<K>(key);
		m_root->color = BLACK;
		m_size++;
		return;
	}

	dest = new rbnode<K>(key);
	if (parentdest->key > key)
	{
		parentdest->left = dest;
	}
	else
	{
		parentdest->right = dest;
	}
	dest->parent = parentdest;
	m_size++;
	

	while (true)
	{
		//case1 空树
		if (!dest->parent)
		{
			dest->color = BLACK;
			return;
		}
		
		//case2 dest节点的父节点颜色是黑色
		if (dest->parent->color == BLACK)
		{
			return;
		}
		else
		{
			//case3 XYr（即LLr RRr LRr RLr）
			if (uncle(dest) && uncle(dest)->color == RED)
			{
				dest->parent->color = BLACK;
				uncle(dest)->color = BLACK;
				grandparent(dest)->color = RED;
				dest = grandparent(dest);
			}
			else
			{
				if (dest->parent == grandparent(dest)->left)
				{
					//case4 LLb
					if (dest == dest->parent->left)
					{
						dest->parent->color = BLACK;
						grandparent(dest)->color = RED;
						llrotate(grandparent(dest));
					}
					else	//case4 LRb
					{
						rrrotate(dest->parent);
						dest = dest->left;
					}
				}
				else
				{
					//case5 RLb
					if (dest == dest->parent->left)
					{
						llrotate(dest->parent);
						dest = dest->right;
					}
					else	//case5 RRb
					{
						 dest->parent->color = BLACK;
						 grandparent(dest)->color = RED;
						 rrrotate(grandparent(dest));
					}
				}
			}
		}
	}
	
	
		
}
