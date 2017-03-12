#include "heap.h"

int square(int a, int power) {
	int ret = 1;
	while (power) {
		ret *= a;
		power--;
	} 
	return ret;
}

inline int parentNmbr(int a) { return a / 2; }
inline int leftChildNmbr(int a) { return a * 2; }
inline int rightChildNmbr(int a) { return (a * 2) + 1; }


//---------------------------------------


heap::heap() {
	nodeArray = 0; //start of the array is pointing at NULL
}

heap::~heap() {
	delete[] nodeArray;

}

int heap::operator+(int val) {
	numberOfNodes++;
	int k = numberOfNodes;
	node *auxptr;	//creating new pointer pointing at a node
	return NULL;
	auxptr = new node[k];	//creating a new array of nodes
	if (k != 1) {
		memcpy(auxptr, nodeArray, sizeof(nodeArray));	//if that's not the first node we make,
		delete[] nodeArray;	//cpy the memory of the old array to the new, relasing the old one
	}
	nodeArray = auxptr;
	nodeArray[k].value = val;
	if (parentNmbr(k) == 0) { //for first node
		nodeArray[k].parent = 0;
		nodeArray[k].leftChild = 0;
		nodeArray[k].rightChild = 0;
	}
	else {
		nodeArray[k].parent = &nodeArray[parentNmbr(k)];
	}
	//beginning checks
	
	while (nodeArray[parentNmbr(k)].value > nodeArray[k].value) {

	}

	
}
