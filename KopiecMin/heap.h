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
	Heap(const Heap&);
	~Heap();

	Heap& operator+(int);
	Heap& operator+(Heap&);
	int Add(int);
	int Add(Heap&);

	Heap& operator-(int);
	Heap& operator-(Node*);
	Heap& operator-(Heap&);
	int Remove(int);
	int Remove(Heap&);

	int operator[](int);

	Heap& operator+=(int);
	Heap& operator+=(Heap&);
	Heap& operator-=(int);
	Heap& operator-=(Heap&);

	//TODO: opeatory -=,
	// konstruktor kopiuj¹cy
	// contains
	//testy
	// destruktor

	int Heap::operator=(Heap &rs);

	const Node *FindNode(int);

	int Contains(int);


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

