#pragma once

#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
//----------------------------------
#include "node.h"

int square(int, int);
inline int parentNmbr(int);
inline int leftChildNmbr(int);
inline int rightChildNmbr(int);


class Heap
{
public:
	Heap();
	~Heap();
	int operator+(int);
	int operator-(int);
	int operator-(Node*);

	Node * SearchHeap(int);
	int SwapCond(Node*);

	unsigned int numberOfNodes = 0;
	vector<Node*> nodeArray;

	void Draw();


};

