#pragma once

enum ncolor
{
	RED,
	BLACK
};

struct rbnode
{
	rbnode* lchild;
	rbnode* rchild;
	rbnode* parent;
	ncolor color;
};

rbnode* parent(rbnode* x);
rbnode* leftRotate(rbnode* tree, rbnode* x);
rbnode* rightRotate(rbnode* tree, rbnode* x);