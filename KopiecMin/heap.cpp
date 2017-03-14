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
	//node *auxptr;	//creating new pointer pointing at a node
	//auxptr = new node[k];	//creating a new array of nodes
	if (k == 1) {
		//memcpy(auxptr, nodeArray, sizeof(nodeArray));	//if that's not the first node we make,
		//delete[] nodeArray;	//cpy the memory of the old array to the new, relasing the old one
		nodeArray = new node[2];
		
	}
	else {
		nodeArray = static_cast<node*> (realloc(nodeArray, sizeof(node)*(k+1) ) ); //casting the returned void to node ptr

	}
	//nodeArray = auxptr;
	if (k != 1) {
		int i;
		node *aux;
		do {	//looks for the nearest empty node
			if (nodeArray[i].leftChild == 0) {
				aux = nodeArray[i].leftChild;
				aux->value = val;
				aux->parent = &nodeArray[i];
				aux->leftChild = 0;
				aux->rightChild = 0;
				k = leftChildNmbr(i);
			}
			if (nodeArray[i].rightChild == 0) {
				aux = nodeArray[i].rightChild;
				aux->value = val;
				aux->parent = &nodeArray[i];
				aux->leftChild = 0;
				aux->rightChild = 0;
				k = rightChildNmbr(i);
			}
			i++;
		} while (nodeArray[i].leftChild == 0 || nodeArray[i].rightChild == 0);
	}

	if (k == 1) { //for first node
		nodeArray[k].parent = 0;
		nodeArray[k].leftChild = 0;
		nodeArray[k].rightChild = 0;
	}
	/*else {
		nodeArray[k].parent = &nodeArray[parentNmbr(k)];
		nodeArray[k].leftChild = 0;
		nodeArray[k].rightChild = 0;
		if (!nodeArray[k].parent->leftChild) {
			nodeArray[k].parent->leftChild = &nodeArray[k];
		}
		else {
			nodeArray[k].parent->rightChild = &nodeArray[k];
		}
	}*/
	//beginning checks
	if (nodeArray[k].parent != 0) {
		
	}
	
	return 1;

	
}

int heap::operator-(int val) {
	node *aux;
	while (aux) {
		aux = searchHeap(val);
		if (!aux) { return 0; }
		node *lc = aux->leftChild;
		node *rc = aux->rightChild;
		if (rc || lc) {
			if (lc && !rc) { //when there is no rightchild
				aux->value = lc->value;
				lc = 0;
				numberOfNodes--;
			}
			else {
				if (lc->value < rc->value) { //when leftchild value is bigger than rightchild
					aux->value = lc->value;
					lc->value = rc->value;
					rc = 0;
					numberOfNodes--;
				}
			}
		}
	}
}

node *heap::searchHeap(int val) {
	//node *aux;
	//aux = nodeArray + 1;
	int n = sizeof(nodeArray) / sizeof(node);
	int i = 1;
	while (i <= n) {
		if (nodeArray[i].value == val) { return nodeArray + i; }
		i++;
	}
	return 0;
}


int heap::swapChild(node *a) {
	while ((nodeArray[parentNmbr(k)].value > nodeArray[k].value) && (k != 1)) {	//changes the value between the new object and the parent, 
		int aux;													//as long as the parent doesn't fit criteria
		aux = nodeArray[parentNmbr(k)].value;
		nodeArray[parentNmbr(k)].value = nodeArray[k].value;
		nodeArray[k].value = aux;
		k = parentNmbr(k);
	}
}
