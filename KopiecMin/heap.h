#pragma once

#include <cmath>

//----------------------------------
#include "node.h"

int square(int, int);

class heap
{
public:
	heap();
	~heap();
	int operator+(int);


	unsigned int numberOfNodes = 0;
	node *nodeArray;



};

