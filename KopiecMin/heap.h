#pragma once

#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
//----------------------------------
#include "node.h"



class Heap
{
public:
	//Heap();	//vectors so no need for that?
	//~Heap();
	int operator+(int);
	int operator+(Heap&);
	int operator-(int);
	int operator-(Node*);
	int operator-(Heap&);

	/*
	friend ostream& operator<<(ostream &os, const Heap &) {
		//string aux = {};
		for (int i = 0; i < ster.nodeArray.size(); i++) {
			os<<"%d ", nodeArray[i]->value;
		}
		os << endl;

		return os;
	}*/


	void Draw();	//crude listing of values
private:
	unsigned int numberOfNodes = 0;
	vector<Node*> nodeArray;

	Node * SearchHeap(int);
	int SwapCond(Node*);

	inline int parentNmbr(int);
	inline int leftChildNmbr(int);
	inline int rightChildNmbr(int);




};

