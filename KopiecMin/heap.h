#pragma once

#include <cmath>
#include <iostream>

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


	unsigned int numberOfNodes = 0;
	node *nodeArray;



};

