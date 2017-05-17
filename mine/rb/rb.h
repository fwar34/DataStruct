#pragma once

enum ncolor
{
	RED,
	BLACK
};

template<typename K, typename V>
struct rbnode
{
	rbnode* left;
	rbnode* right;
	rbnode* parent;
	ncolor color;
	K key;
	V value;
};

template<typename K, typename V>
rbnode<K, V>* leftRotate(rbnode<K, V>* x);

template<typename K, typename V>
rbnode<K, V>* rightRotate(rbnode<K, V>* x);

template<typename K, typename V>
class rbtree
{
private:
	rbtree* root;
	
public:
	void insert(rbnode<K, V>* x);
	void del(rbnode<K, V>* x);
	void search(K key);
	void output();
};