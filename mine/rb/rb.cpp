#include <iostream>
#include "rb.h"

template<typename K, typename V>
rbnode<K, V>* leftRotate(rbnode<K, V>* x)
{
	if (!x)
	{
		return NULL;
	}

	rbnode<K, V>* y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->left = x;
	y->parent = x->parent;
	if (x->parent->left == x)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	x->parent = y;

	if (!y->parent)
	{
		return y;
	}
}