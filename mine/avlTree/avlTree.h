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
	size_t size()
	{
		return m_size;
	}
	void insert(K key);
	void remove(K key);
};

template <typename K>
void avltree<K>::llrotate(avlnode<K>* pa, avlnode<K>* a, avlnode<K>* ca)
{
	a->left = ca->right;
	ca->right = a;
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
	a->right = ca->left;
	ca->left = a;
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
	ca->right = x->left;
	a->left = x->right;
	x->left = ca;
	x->right = a;
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
	a->right = x->left;
	ca->left = x->right;
	x->left = a;
	x->right = ca;
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
void avltree<K>::insert(K key)
{
	avlnode<K>* p = m_root;
	avlnode<K>* pp = NULL;
	avlnode<K>* a = NULL;
	avlnode<K>* pa = NULL;

	while (p)
	{
		//p->bf等于1或者-1
		if (p->bf)
		{
			a = p;
			pa = pp;
		}
		
		pp = p;
		if (p->key > key)
		{
			p = p->left;
		}
		else if (p->key < key)
		{
			p = p->right;
		}
		else
		{
			//有相同key的节点直接退出
			return;
		}
	}

	avlnode<K>* r = new avlnode<K>(key);
	m_size++;

	if (m_root)
	{
		if (pp->key > key)
		{
			pp->left = r;
		}
		else
		{
			pp->right = r;
		}
	}
	else
	{
		m_root = r;
		return;
	}

	if (a)
	{
		if (a->bf == 1)
		{
			if (a->key > key)
			{
				avlnode<K>* b = a->left;
				if (b->key > key)
				{
					//LL
					fixbf(b->left, r, key);
					llrotate(pa, a, b);
				}
				else
				{
					//LR
					fixbf(b->right, r, key);
					lrrotate(pa, a, b);
				}
			}
			else
			{
				a->bf = 0;
				fixbf(a->right, r, key);
			}
		}
		else  //a->bf == -1
		{
			if (a->key > key)
			{
				a->bf = 0;
				fixbf(a->left, r, key);
			}
			else
			{
				avlnode<K>* b = a->right;
				if (b->key > key)
				{
					//RL
					fixbf(b->left, r, key);
					rlrotate(pa, a, b);
				}
				else
				{
					//RR
					fixbf(b->right, r, key);
					rrrotate(pa, a, b);
				}
			}
		}		
	}
	else
	{
		fixbf(m_root, r, key);
	}
}