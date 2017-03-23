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

	//METHODS
	//////////////////////
	Heap();//+
	Heap(const Heap&);//+
	~Heap();//+no mem leaks

	Heap& operator+(int);//+
	Heap& operator+(Heap&);//+
	int Add(int);//+
	int Add(Heap&);//+

	Heap& operator-(int);//+
	Heap& operator-(Heap&);//+
	int Remove(int);//+
	int Remove(Node *);
	int Remove(Heap&);//+

	int operator[](int);
	int Size();

	Heap& operator+=(int);
	Heap& operator+=(Heap&);
	Heap& operator-=(int);
	Heap& operator-=(Heap&);

	//TODO: opeatory -=,
	// konstruktor kopiuj¹cy
	// contains
	//testy
	// destruktor

	Heap& operator=(Heap &rs);

	const Node *FindNode(int);

	int Contains(int);

	//COMPARE OPERATORS
	/////////////////////////////

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
		return (!operator>(rs));
	}

	inline bool operator>= (const Heap &rs) {
		return (!operator<(rs));
	}

	inline bool operator== (Heap &rs) {
		if (nodeArray.size() != rs.nodeArray.size()) { return false; }
		for (int i = 0; i < nodeArray.size(); i++) {
			if(this->Contains(nodeArray[i]->value)!=rs.Contains(nodeArray[i]->value))
			{
				return false;
			}
		}
		return true;
	}

	inline bool operator!= (Heap &rs) { 
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

	//METHODS
	/////////////////
	int SwapCond(Node*);
	Node *FindNodePriv(int);

	inline int parentNmbr(int);
	inline int leftChildNmbr(int);
	inline int rightChildNmbr(int);


	//VARIABLES
	//////////////////////
	vector<Node*> nodeArray;

	friend class HeapTester;

};

