/*************************************************************************
    > File Name: avlTree.h
    > Author: Feng
    > Created Time: 2017年05月23日 星期二 10时54分11秒
    > Content: 非递归实现插入删除
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename K>
struct avlnode
{
	avlnode* left;
	avlnode* right;
	K key;
	int bf;
	avlnode(K k) : left(NULL), right(NULL), key(k), bf(0)
	{
	}
};

template <typename K>
class avltree
{
private:
	avlnode<K>* m_root;
	size_t m_size;

	void insert(avlnode<K>* tree, K key);
	void remove(avlnode<K>* tree, K key);
	void llrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca);
	void rrrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca);
	void lrrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca);
	void rlrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca);
	void fixbf(avlnode<K>* a, avlnode<K>* r, K key);

public:
	avltree() : m_root(NULL), m_size(0)
	{
	}

	bool empty();
	size_t size();
	void insert(K key);
	void remove(K key);
};

template <typename K>
void avltree<K>::llrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca)
{
	ca->right = a;
	a->left = ca->right;
	if (pa)
	{
		if (a == pa->left)
		{
			pa->left = ca;
		}
		else
		{
			pa->right = ca;
		}
	}
	else
	{
		m_root = ca;
	}

	a->bf = ca->bf = 0;
}

template <typename K>
void avltree<K>::rrrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca)
{
	ca->left = a;
	a->right = ca->left;
	if (pa)
	{
		if (a == pa->left)
		{
			pa->left = ca;
		}
		else
		{
			pa->right = ca;
		}
	}
	else
	{
		m_root = ca;
	}

	a->bf = ca->bf = 0;
}

template <typename K>
void avltree<K>::lrrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca)
{
	avlnode<K>* x = ca->right;
	x->left = ca;
	x->right = a;
	ca->right = x->left;
	a->left = x->right;
	if (pa)
	{
		if (a == pa->left)
		{
			pa->left = x;
		}
		else
		{
			pa->right = x;
		}
	}
	else
	{
		m_root = x;
	}

	if (x->bf == 0)
	{
		a->bf = ca->bf = 0;
	}
	else if (x->bf == 1)
	{
		a->bf = -1;
		ca->bf = 0;
	}
	else
	{
		a->bf = 0;
		ca->bf = 1;
	}
	x->bf = 0;
}

template <typename K>
void avltree<K>::rlrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca)
{
	avlnode<K>* x = ca->left;
	x->left = a;
	x->right = ca;
	a->right = x->left;
	ca->left = x->right;
	if (pa)
	{
		if (a == pa->left)
		{
			pa->left = x;
		}
		else
		{
			pa->right = x;
		}
	}
	else
	{
		m_root = x;
	}

	if (x->bf == 0)
	{
		a->bf = ca->bf = 0;
	}
	else if (x->bf == 1)
	{
		a->bf = 0;
		ca->bf = -1;
	}
	else
	{
		a->bf = 1;
		ca->bf = 0;
	}
	x->bf = 0;
}

template <typename K>
void avltree<K>::fixbf(avlnode<K>* a, avlnode<K>* r, K key)
{
	while (a != r)
	{
		if (a->key > key)
		{
			a->bf = 1;
			a = a->left;
		}
		else
		{
			a->bf = -1;
			a = a->right;
		}
	}
	
}

template <typename K>
void avltree<K>::insert(avlnode<K>* tree, K key)
{

}