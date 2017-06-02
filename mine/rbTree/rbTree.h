/*************************************************************************
    > File Name: rbTree.h
    > Author: Feng
    > Created Time: 2017年05月27日 星期六 15时20分40秒
    > Content: rbTree
 ************************************************************************/

#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


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
	rbnode<K>* root()
	{
		return m_root;
	}
	void printtree();
	void levelout();
	void insert(K key);
	void remove(K key);
	size_t size()
	{
		return m_size;
	}
	int height()
	{
		return height(m_root);
	}
	void PrintBinaryTree();

private:
	rbnode<K>* grandparent(rbnode<K>* node);
	rbnode<K>* uncle(rbnode<K>* node);
	void llrotate(rbnode<K>* node);
	void rrrotate(rbnode<K>* node);
	void printtree(rbnode<K>* tree, int height, int totalheight);
	int height(rbnode<K>* tree);
	void PrintNode(vector<rbnode<K>*>& nodes, int level, int max_level);
	void PrintWhiteSpaces(int num);
	bool IsAllElementsNULL(const vector<rbnode<K>*> &nodes);
};

template <typename K>
void rbtree<K>::levelout()
{
	int totalheight = height(m_root);
	size_t curcount = 1;
	size_t nextcount = 0;
	std::queue<rbnode<K>*> q;
	rbnode<K>* node = NULL;

	if (!m_root)
	{
		return;
	}
	
	q.push(m_root);
	while (!q.empty())
	{
		for (int i = 0; i < totalheight; ++i)
		{
			std::cout << " ";
		}
		totalheight--;
		
		node = q.front();
		q.pop();
		std::cout << node->key << "," << (node->color == RED ? "R" : "B");
		for (int i = 0; i < totalheight; ++i)
		{
			cout << " ";
		}
		
		curcount--;

		if (node->left)
		{
			q.push(node->left);
			nextcount++;
		}
		
		if (node->right)
		{
			q.push(node->right);
			nextcount++;
		}
		
		if (curcount == 0)
		{
			curcount = nextcount;
			nextcount = 0;
			std::cout << std::endl;
		}
	}
}

template <typename K>
int rbtree<K>::height(rbnode<K>* tree)
{
	if (!tree)
	{
		return 0;
	}
	
	int left = height(tree->left);
	int right = height(tree->right);

	return left > right ? left + 1 : right + 1;
}

template <typename K>
void rbtree<K>::printtree()
{
	int total = height(m_root);
	for (int i = 0, j = total; i <= total; ++i, j--)
	{
		for (int count = 0; count < j; ++count)
		{
			std::cout << "   ";
		}
		
		printtree(m_root, i, total);
		std::cout << std::endl;
	}
}

template <typename K>
void rbtree<K>::printtree(rbnode<K>* tree, int height, int totalheight)
{
	if (!tree || height < 0)
	{
		return;
	}
	
	if (height == 0)
	{
		std::cout << tree->key << "," << (tree->color == RED ? "R" : "B");
		for (int i = 0; i < totalheight - height; ++i)
		{
			std::cout << " ";
		}
		return;
	}
	
	printtree(tree->left, height - 1, totalheight);
	printtree(tree->right, height - 1, totalheight);
}

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
	if (node->left)
	{
		node->left->parent = node;
	}
	
	x->right = node;
	if (node == m_root)
	{
		m_root = x;
		x->parent = NULL;
	}
	else
	{
		if (node == node->parent->left)
		{
			node->parent->left = x;
		}
		else
		{
			node->parent->right = x;
		}
		x->parent = node->parent;
	}
	node->parent = x;
}

template <typename K>
void rbtree<K>::rrrotate(rbnode<K>* node)
{
	rbnode<K>* x = node->right;
	node->right = x->left;
	if (node->right)
	{
		node->right->parent = node;
	}
	x->left = node;
	if (node == m_root)
	{
		m_root = x;
		x->parent = NULL;
	}
	else
	{
		if (node == node->parent->left)
		{
			node->parent->left = x;
		}
		else
		{
			node->parent->right = x;
		}
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

	//有相同的key直接返回
	if (dest)
	{
		std::cout << "exist key " << key << std::endl;
		return;
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
			else	//XYb
			{
				if (dest->parent == grandparent(dest)->left)
				{
					//case4 LLb
					if (dest == dest->parent->left)
					{
						dest->parent->color = BLACK;
						grandparent(dest)->color = RED;
						llrotate(grandparent(dest));
						return;
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
						 return;
					}
				}
			}
		}
	}	
}


//////////////////////////////////////////////////////////////////////////
template <typename K>
void rbtree<K>::PrintWhiteSpaces(int num)  
{  
	for (int i = 0; i < num; ++i)
	{
		cout << " ";  
	}
}  

template <typename K>
void rbtree<K>::PrintNode(vector<rbnode<K>*>& nodes, int level, int max_level)  
{  
	if (nodes.empty() || IsAllElementsNULL(nodes)) 
	{
		return; // exit  
	}

	int floor = max_level - level;  
	int endge_lines = 1 << (std::max(floor - 1, 0));  
	int first_spaces = (1 << floor) - 1;  
	int between_spaces = (1 << (floor+1)) - 1;  

	PrintWhiteSpaces(first_spaces);  

	// print the 'level' level   
	vector<rbnode<K>*> new_nodes;  
	typename::vector<rbnode<K>*>::const_iterator it = nodes.begin();  
	for (; it != nodes.end(); ++it)
	{  
		if (*it != NULL)
		{  
			cout << (*it)->key << "," << ((*it)->color == RED ? "R" : "B");  
			new_nodes.push_back((*it)->left);  
			new_nodes.push_back((*it)->right);  
		}  
		else
		{  
			new_nodes.push_back(NULL);  
			new_nodes.push_back(NULL);  
			cout << " ";  
		}  
		PrintWhiteSpaces(between_spaces);  
	}  
	cout << endl;  

	// print the following /s and \s  
	for (int i = 1; i <= endge_lines; ++i)
	{  
		for(int j = 0; j < nodes.size(); ++j)
		{  
			PrintWhiteSpaces(first_spaces - i);  
			if (nodes[j] == NULL)
			{  
				PrintWhiteSpaces(endge_lines + endge_lines + i + 1);  
				continue;  
			}  
			if (nodes[j]->left != NULL)  
			{
				cout << "/";  
			}
			else  
			{
				PrintWhiteSpaces(1);  
			}

			PrintWhiteSpaces(i + i - 1);  

			if (nodes[j]->right != NULL)  
			{
				cout << "\\";  
			}
			else  
			{
				PrintWhiteSpaces(1);  
			}

			PrintWhiteSpaces(endge_lines + endge_lines - i);  
		}  
		cout << endl;  
	}  

	PrintNode(new_nodes, level + 1, max_level);  

}  

// test whether all elements in vector are NULL  
template <typename K>
bool rbtree<K>::IsAllElementsNULL(const vector<rbnode<K>*> &nodes)  
{  
	typename::vector<rbnode<K>*>::const_iterator it = nodes.begin();  

	while (it != nodes.end())
	{  
		if (*it) 
		{
			return false;   
		}
		++it;  
	}  
	return true;  
}  

template <typename K>
void rbtree<K>::PrintBinaryTree()  
{  
	int max_level = height(m_root);  
	vector<rbnode<K>*> nodes;  

	nodes.push_back(m_root);  

	PrintNode(nodes, 1, max_level);  
}  