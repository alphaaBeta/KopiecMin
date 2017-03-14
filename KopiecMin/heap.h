#pragma once

#include <cmath>
#include <iostream>
#include <cstring>


using namespace std;
//----------------------------------
#include "node.h"

int square(int, int);
inline int parentNmbr(int);
inline int leftChildNmbr(int);
inline int rightChildNmbr(int);


class heap
{
public:
	heap();
	~heap();
	int operator+(int);
	int operator-(int);

	node *searchHeap(int);
	int swapChild(node*);

	unsigned int numberOfNodes = 0;
	node *nodeArray;



};

