/*************************************************************************
    > File Name: binarySearchTree.h
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时34分51秒
    > Content: 二叉搜索树
 ************************************************************************/
#pragma once

template <typename K>
struct bsnode
{
	bsnode* left;
	bsnode* right;
	K key;
};

template <typename K>
class bstree
{
private:
	bsnode<K>* m_root;

public:
	void insert(K key);
	void remove(K key);
	bool contains(K key);
	bsnode<K>* search(K key);
	void ptree();
	bool empty();
	K min();
	K max();

private:
	void ptree(bsnode<K>* tree);
};
