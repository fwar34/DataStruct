#include <iostream>
#include "rb.h"

rbnode* parent(rbnode* x)
{
	if (!x)
	{
		return NULL;
	}

	return x->parent;
}