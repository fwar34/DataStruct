/*************************************************************************
    > File Name: avlTree.h
    > Author: Feng
    > Created Time: 2017年05月23日 星期二 10时54分11秒
    > Content: 非递归实现插入删除
 ************************************************************************/

#include <iostream>
#include <stack>
#include <queue>

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
	void levelout();
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
					fixbf(b->right, r, key);		//这里必须先修正bf，在lrrotate中要按照修正后x的bf给a和b节点重新计算bf
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
					fixbf(b->left, r, key);		//这里必须先修正bf，在lrrotate中要按照修正后x的bf给a和b节点重新计算bf
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

template <typename K>
void avltree<K>::remove(K key)
{
	stack<avlnode<K>*> stk;

	avlnode<K>* p = m_root;
	while (p && p->key != key)
	{
		stk.push(p);
		if (p->key > key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	
	//没找到key相等的节点直接退出
	if (!p)
	{
		return;
	}
	
	if (p->left && p->right)
	{
		stk.push(p);
		avlnode<K>* dest = p->left;
		while (dest->right)
		{
			stk.push(dest);
			dest = dest->right;
		}
		
		p->key = dest->key;
		p = dest;
	}

	K pkey = p->key;
	
	avlnode<K>* x = NULL;
	if (p->left)
	{
		x = p->left;
	}
	else
	{
		x = p->right;
	}

	if (p == m_root)
	{
		m_root = x;
		m_size--;
		delete p;
		return;
	}
	else
	{
		if (stk.top()->left == p)
		{
			stk.top()->left = x;
		}
		else
		{
			stk.top()->right = x;
		}
	}
	m_size--;
	delete p;

	avlnode<K>* q = NULL;
	q = stk.top();
	stk.pop();

	while (q)
	{
		//这里一定是>=不是>，等于是给要删除的节点有两
		//个节点儿子节点的情况准备的，因为把左边儿子的最大值赋值给了p节点
		if (q->key >= pkey)		
		{
			q->bf--;
			if (q->bf == 0)
			{
				//q的高度改变了，但是q还是平衡的，继续往根节点走		
				if (stk.empty())
				{
					return;
				}
				q = stk.top();
				stk.pop();
			}
			else if (q->bf == -1)
			{
				//q的高度未改变，直接退出
				return;
			}
			else	//q->bf == -2
			{
				//q的高度改变了并且q不平衡了，然后根据q的右儿子节点的bf来确定下步
				avlnode<K>* b = q->right;
				avlnode<K>* pa = NULL;
				if (!stk.empty())
				{
					pa = stk.top();
					stk.pop();
				}
				
				switch (b->bf)
				{
				case 0:
					rrrotate(pa, q, b);
					q->bf = -1;		// q is A node
					b->bf = 1;
					return;
				case 1:
					rlrotate(pa, q, b);
					break;
				case -1:
					rrrotate(pa, q, b);
				}
				q = pa;
			}
		}
		else
		{
			q->bf++;
			if (q->bf == 0)
			{
				if (stk.empty())
				{
					return;
				}
				
				q = stk.top();
				stk.pop();
			}
			else if (q->bf == 1)
			{
				return;
			}
			else	//q->bf == 2
			{
				avlnode<K>* b = q->left;
				avlnode<K>* pa = NULL;
				pa = stk.top();
				stk.pop();
				switch (b->bf)
				{
				case 0:
					llrotate(pa, q, b);
					q->bf = 1;
					b->bf = -1;
					return;
				case 1:
					llrotate(pa, q, b);
					break;
				case -1:
					lrrotate(pa, q, b);
				}
				q = pa;
			}
		}
	}
}

template <typename K>
void avltree<K>::levelout()
{
	int curcount = 1;
	int nextcount = 0;
	queue<avlnode<K>*> q;

	if (!m_root)
	{
		return;
	}

	avlnode<K>* x = NULL;

	q.push(m_root);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		curcount--;
		cout << x->key << " ";

		if (x->left)
		{
			q.push(x->left);
			nextcount++;
		}
		
		if (x->right)
		{
			q.push(x->right);
			nextcount++;
		}
		
		if (!curcount)
		{
			cout << endl;
			curcount = nextcount;
			nextcount = 0;
		}
	}
}