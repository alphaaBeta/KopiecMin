#pragma once

#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
//----------------------------------
#include "node.h"




/////////////////////////////////


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
	int operator[](int);

	int Heap::operator=(Heap &rs);

	Node * SearchHeap(int);


	inline bool operator< (const Heap &rs) {
		if (nodeArray.size() < rs.nodeArray.size()) {
			return true;
		}
		else return false;
	}

	inline bool operator> (const Heap &rs) {
		if (nodeArray.size() > rs.nodeArray.size()) {
			return true;
		}
		else return false;
	}

	inline bool operator<= (const Heap &rs) {
		return (!operator<(rs));
	}

	inline bool operator>= (const Heap &rs) {
		return (!operator>(rs));
	}

	inline bool operator== (const Heap &rs) {
		if (nodeArray.size() == rs.nodeArray.size()) { return true; }
		else { return false; }
	}

	inline bool operator!= (const Heap &rs) { 
		return (!operator==(rs)); 
	}


	friend ostream& operator<<(ostream &os, const Heap &ster) { //crude listing of values
		//string aux = {};
		for (int i = 0; i < ster.nodeArray.size(); i++) {
			os << ster.nodeArray[i]->value << " ";
		}
		os << endl << ster.nodeArray.size() << endl;

		return os;
	}

private:
	unsigned int numberOfNodes = 0;
	vector<Node*> nodeArray;

	int SwapCond(Node*);

	inline int parentNmbr(int);
	inline int leftChildNmbr(int);
	inline int rightChildNmbr(int);




};

