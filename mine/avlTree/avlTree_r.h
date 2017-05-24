/*************************************************************************
> File Name: avlTree.h
> Author: Feng
> Created Time: 2017年05月22日 星期一 13时47分38秒
> Content: avltree 自底向上，添加删除递归实现
************************************************************************/
#pragma once

#include <algorithm>
#include <iostream>

template <typename K>
struct avlnode
{
	avlnode* left;
	avlnode* right;
	int height;
	K key;
	avlnode(K k) : left(NULL), right(NULL), height(0), key(k)
	{
	}
};

template <typename K>
class avltree
{
public:
	avltree() : m_root(NULL), m_nodecount(0)
	{
	}

	void insert(K key);
	void insert2(K key);
	void remove(K key);
	void makeempty();
	bool empty();
	int height();
	int size()
	{
		return m_nodecount;
	}

private:
	void insert(avlnode<K>*& tree, K key);
	//insert2和insert1不同的地方是insert1传递的引用，insert2返回的是节点指针
	avlnode<K>* insert2(avlnode<K>* tree, K key);
	avlnode<K>* remove(avlnode<K>* tree, K key);
	avlnode<K>* llrotate(avlnode<K>* node);
	avlnode<K>* rrrotate(avlnode<K>* node);
	avlnode<K>* lrrotate(avlnode<K>* node);
	avlnode<K>* rlrotate(avlnode<K>* node);
	int height(avlnode<K>* tree);

	avlnode<K>* m_root;
	int m_nodecount;
};

template <typename K>
int avltree<K>::height()
{
	return height(m_root);
}

template <typename K>
int avltree<K>::height(avlnode<K>* tree)
{
	if (!tree)
	{
		return -1;
	}
	return tree->height;
}

template <typename K>
avlnode<K>* avltree<K>::llrotate(avlnode<K>* node)
{
	if (!node)
	{
		return NULL;
	}

	avlnode<K>* x = node->left;
	node->left = x->right;
	x->right = node;

	node->height = std::max(height(node->left), height(node->right)) + 1;
	x->height = std::max(height(x->left), height(x->right)) + 1;

	return x;
}

template <typename K>
avlnode<K>* avltree<K>::rrrotate(avlnode<K>* node)
{
	if (!node)
	{
		return NULL;
	}

	avlnode<K>* x = node->right;
	node->right = x->left;
	x->left = node;

	node->height = std::max(height(node->left), height(node->right)) + 1;
	x->height = std::max(height(x->left), height(x->right)) + 1;

	return x;
}

template <typename K>
avlnode<K>* avltree<K>::lrrotate(avlnode<K>* node)
{
	if (!node)
	{
		return NULL;
	}

	node->left = rrrotate(node->left);
	return llrotate(node);
}

template <typename K>
avlnode<K>* avltree<K>::rlrotate(avlnode<K>* node)
{
	if (!node)
	{
		return NULL;
	}
	node->right = llrotate(node->right);
	return rrrotate(node);
}

template <typename K>
void avltree<K>::insert(avlnode<K>*& tree, K key)
{
	if (!tree)
	{
		tree = new avlnode<K>(key);
		++m_nodecount;
		return;
	}

	if (tree->key > key)
	{
		insert(tree->left, key);
		//往tree的左子树添加节点的话，tree不平衡的时候height(tree->left) - height(tree->right)只可能是2不可能是-2
		//这里不能直接用height(tree) == 2来判断，因为height(tree)这时候不准，还没有重新计算
		if (height(tree->left) - height(tree->right) == 2)
		{
			//这里也可以用if (height(tree->left->left) > height(tree->left->right))来判断
			//if (height(tree->left->left) > height(tree->left->right))
			if (key < tree->left->key)
			{
				tree = llrotate(tree);
			}
			else
			{
				tree = lrrotate(tree);
			}
		}
		else
		{
			//重新计算tree的高度
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else if (tree->key < key)
	{
		insert(tree->right, key);
		//往tree的右子树添加节点的话，tree不平衡的时候height(tree->left) - height(tree->right)只可能是-2不可能是2
		//这里不能直接用height(tree) == -2来判断，因为height(tree)这时候不准，还没有重新计算
		if (height(tree->left) - height(tree->right) == -2)
		{
			//这里也可以用if (height(tree->right->right) > height(tree->right->left))来判断
			//if (height(tree->right->right) > height(tree->right->left))
			if (key > tree->right->key)
			{
				tree = rrrotate(tree);
			}
			else
			{
				tree = rlrotate(tree);
			}
		}	
		else
		{
			//重新计算tree的高度
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else
	{
		//key相等的时候啥都不做
		//std::cout << "key " << key << " exist" << std::endl;
	}
}

template <typename K>
void avltree<K>::insert(K key)
{
	insert(m_root, key);
}

template <typename K>
void avltree<K>::insert2(K key)
{
	m_root = insert2(m_root, key);
}

template <typename K>
avlnode<K>* avltree<K>::insert2(avlnode<K>* tree, K key)
{
	if (!tree)
	{
		tree = new avlnode<K>(key);
		++m_nodecount;
		return tree;
	}

	if (tree->key > key)
	{
		tree->left = insert2(tree->left, key);
		if (height(tree->left) - height(tree->right) == 2)
		{
			//这里也可以用if (height(tree->left->left) > height(tree->left->right))来判断
			//if (height(tree->left->left) > height(tree->left->right))
			if (key < tree->left->key)
			{
				tree = llrotate(tree);
			}
			else
			{
				tree = lrrotate(tree);
			}
		}
		else
		{
			//tree的高度不平衡的时候在旋转函数中旋转完已经重新计算了tree的高度，所以只有这里要重新计算tree的高度
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else if (tree->key < key)
	{
		tree->right = insert2(tree->right, key);
		if (height(tree->left) - height(tree->right) == -2)
		{
			//这里也可以用if (height(tree->right->right) > height(tree->right->left))来判断
			//if (height(tree->right->right) > height(tree->right->left))
			if (key > tree->right->key)
			{
				tree = rrrotate(tree);
			}
			else
			{
				tree = rlrotate(tree);
			}
		}
		else
		{
			//tree的高度不平衡的时候在旋转函数中旋转完已经重新计算了tree的高度，所以只有这里要重新计算tree的高度
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else
	{
		//key相等的时候啥都不做
		//std::cout << "key " << key << " exist" << std::endl;
	}

	return tree;
}

template <typename K>
void avltree<K>::remove(K key)
{
	remove(m_root, key);
}

template <typename K>
avlnode<K>* avltree<K>::remove(avlnode<K>* tree, K key)
{
	if (!tree)
	{
		return NULL;
	}

	if (tree->key > key)
	{
		tree->left = remove(tree->left, key);
		if (height(tree->left) - height(tree->right) == -2)
		{
			//因为height(tree->left) - height(tree->right) == -2所以tree肯定有右儿子（tree->right肯定不为空）
			if (height(tree->right->right) > height(tree->right->left))
			{
				tree = rrrotate(tree);
			}
			else
			{
				tree = rlrotate(tree);
			}
		}
		else
		{
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else if (tree->key < key)
	{
		tree->right = remove(tree->right, key);
		if (height(tree->left) - height(tree->right) == 2)
		{
			//因为height(tree->left) - height(tree->right) == 2所以tree肯定有左儿子（tree->left肯定不为空）
			if (height(tree->left->left) > height(tree->left->right))
			{
				tree = llrotate(tree);
			}
			else
			{
				tree = lrrotate(tree);
			}
		}
		else
		{
			tree->height = std::max(height(tree->left), height(tree->right)) + 1;
		}
	}
	else
	{
		//要删除的节点有两个儿子节点
		if (tree->left && tree->right)
		{
			avlnode<K>* x = tree->left;
			//while执行完成x指向了tree的左子树的最大节点
			while (x->right)
			{
				x = x->right;
			}
			tree->key = x->key;
			//先找出tree的左子树的最大节点，将tree的左子树最大节点的值拷贝到tree，再删除tree的左子树的最大节点
			tree->left = remove(tree->left, x->key);
			if (height(tree->left) - height(tree->right) == -2)
			{
				if (height(tree->right->right) > height(tree->right->left))
				{
					tree = rrrotate(tree);
				}
				else
				{
					tree = rlrotate(tree);
				}
			}
			else
			{
				tree->height = std::max(height(tree->left), height(tree->right)) + 1;
			}
		}
		else
		{
			avlnode<K>* y = tree;
			if (tree->left)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}

			m_nodecount--;
			delete y;
		}
	}

	return tree;
}