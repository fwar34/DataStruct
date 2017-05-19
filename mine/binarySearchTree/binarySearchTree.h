#ifndef _BINARY_SEARCH_TREE_H__
#define _BINARY_SEARCH_TREE_H__
/*************************************************************************
    > File Name: binarySearchTree.h
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时34分51秒
    > Content: 二叉搜索树
 ************************************************************************/
#include <iostream>
using namespace std;

template <typename K>
struct bsnode
{
	bsnode* left;
	bsnode* right;
	K key;
	bsnode(K k)
	{
		left = NULL;
		right = NULL;
		key = k;
	}
};

template <typename K>
class bstree
{
private:
	bsnode<K>* m_root;
	size_t m_elenum;

public:
	bstree() : m_root(NULL), m_elenum(0)
	{
	}

	void insert(K key);
	void insert_r(K key);
	void remove(K key);
	bool contains(K key);
	bsnode<K>* search(K key);
	void ptree();
	bool empty();
	K& min();
	K& max();
	size_t count()
	{
		return m_elenum;
	}

private:
	bsnode<K>* search(bsnode<K>* tree, K key);
	void ptree(bsnode<K>* tree);
	bsnode<K>* min(bsnode<K>* tree);
	bsnode<K>* max(bsnode<K>* tree);
	//tree传递指针引用是因为tree是空的话在内部创建新的node的同时更新tree指针
	void insert_r(bsnode<K>*& tree, K key);
};

template <typename K>
void bstree<K>::insert(K key)
{
	if (!m_root)
	{
		m_root = new bsnode<K>(key);
		++m_elenum;
		return;
	}

	bsnode<K>* del = m_root;
	bsnode<K>* parentdel = NULL;
	while (del && del->key != key)
	{
		parentdel = del;
		if (del->key > key)
		{
			del = del->left;
		}
		else
		{
			del = del->right;
		}
	}

	//有key相等的节点直接退出
	if (del)
	{
		cout << "insert " << key << " exist" << endl;
		return;
	}

	bsnode<K>* newnode = new bsnode<K>(key);
	if (parentdel->key > key)
	{
		parentdel->left = newnode;
	}
	else
	{
		parentdel->right = newnode;
	}
	++m_elenum;
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
		tree = new bsnode<K>(key);
		++m_elenum;
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
	else
	{
		cout << "insert " << key << " exist" << endl;
	}
}

template <typename K>
void bstree<K>::remove(K key)
{
	if (!m_root)
	{
		return;
	}

	bsnode<K>* del = m_root;
	bsnode<K>* parentdel = NULL;
	bsnode<K>* childdel = NULL;

	//这个while执行完成后del就指向了与key相等的节点
	//parentdel就指向了del的父节点（如果del是root节点则parentdel就为空）
	while (del && del->key != key)
	{
		parentdel = del;
		if (del->key > key)
		{
			del = del->left;
		}
		else
		{
			del = del->right;
		}
	}

	//没有找到key相等的节点直接退出
	if (!del)
	{
		return;
	}

	//要删除的节点有两个子节点
	if (del->left && del->right)
	{
		bsnode<K>* maxnode = del->left;
		bsnode<K>* parentmax = del;
		//这个while执行完成后maxnode就指向了del的左子树的最大节点
		//parentmax就指向了maxnode的父节点
		while (maxnode && maxnode->right)
		{
			parentmax = maxnode;
			maxnode = maxnode->right;
		}

		//如果要删除的节点的左子树的最大值就是要删除节点的左孩子
		//就只把最大节点的右孩子重新赋值
		if (parentmax == del)
		{
			maxnode->right = parentmax->right;
		}
		else
		{
			if (maxnode->left)
			{
				parentmax->right = maxnode->left;
			}
			else
			{
				parentmax->right = NULL;
			}
			maxnode->left = del->left;
			maxnode->right = del->right;
		}

		//要删除的是root节点
		if (del == m_root)
		{
			m_root = maxnode;
		}
		else
		{
			if (del == parentdel->left)
			{
				parentdel->left = maxnode;
			}
			else
			{
				parentdel->right = maxnode;
			}
		}

		--m_elenum;
		delete del;
	}
	//要删除的节点只有一个子节点
	else if ((del->left && !del->right) || (!del->left && del->right))
	{
		if (del->left)
		{
			childdel = del->left;
		}
		else
		{
			childdel = del->right;
		}

		//要删除的是root节点
		if (del == m_root)
		{
			m_root = childdel;
		}
		else
		{
			if (del == parentdel->left)
			{
				parentdel->left = childdel;
			}
			else
			{
				parentdel->right = childdel;
			}
		}

		--m_elenum;
		delete del;
	}
	//要删除的节点是个叶子节点
	else
	{
		//要删除的是root节点
		if (del == m_root)
		{
			m_root = NULL;
		}
		else
		{
			if (del == parentdel->left)
			{
				parentdel->left = NULL;
			}
			else
			{
				parentdel->right = NULL;
			}
		}

		--m_elenum;
		delete del;
	}
}

template <typename K>
bool bstree<K>::empty()
{
	return m_root == NULL;
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
bsnode<K>* bstree<K>::search(bsnode<K>* tree, K key)
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

template <typename K>
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

template <typename K>
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

#endif