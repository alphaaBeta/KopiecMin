#pragma once

#include "heap.h"


class Node
{
public:
	Node *parent, *leftChild, *rightChild;
	int value;
};

