#include "heap.h"


int square(int a, int power) {
	int ret = 1;
	while (power) {
		ret *= a;
		power--;
	} 
	return ret;
}

inline int parentNmbr(int a) { return (a-1) / 2; }
inline int leftChildNmbr(int a) { return a * 2 + 1; }
inline int rightChildNmbr(int a) { return (a * 2) + 2; }


//---------------------------------------


heap::heap() {
	nodeArray = 0; //start of the array is pointing at NULL
	cout << "fuu";

}

heap::~heap() {
	delete[] nodeArray;

}

int heap::operator+(int val) {
	int k = numberOfNodes;


	if (k == 0) {
		nodeArray = new node[1];
		nodeArray->value = val;
		nodeArray->parent = 0;
		nodeArray->leftChild = 0;
		nodeArray->rightChild = 0;
		numberOfNodes++;
		return 1;
		
	}
	else {
		nodeArray = static_cast<node*> (realloc(nodeArray, sizeof(node)*(k+1) ) ); //casting the returned void to node ptr
		nodeArray[k].value = val;
		nodeArray[k].parent = &nodeArray[parentNmbr(k)];
		nodeArray[k].leftChild = 0;
		nodeArray[k].rightChild = 0;
		swapCond(&nodeArray[k]); //nodeArray[1]

	}
	
	
	numberOfNodes++;
	
	return 1;

	
}

int heap::operator-(int val) {
	node *aux;
	return 0;
	while (1) {
		aux = searchHeap(val);
		if (!aux) { return 0; }
		node *lc = aux->leftChild;
		node *rc = aux->rightChild;
		if (rc || lc) {
			if (lc && !rc) { //when there is no rightchild
				aux->value = lc->value;
				lc = 0; // xD
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


int heap::swapCond(node *a) {
	while (a->parent && a->parent->value > a->value) {	//changes the value between the new object and the parent, 
		int aux = a->value;													//as long as the parent doesn't fit criteria
		a->value = a->parent->value;
		a->parent->value = aux;
		a = a->parent;
	}
	//if(!a->leftChild && ) {
		while ((a->leftChild && a->leftChild->value < a->value) ||
				(a->rightChild && a->rightChild->value < a->value)) {

			if (a->leftChild->value < a->rightChild->value) {
				int aux = a->rightChild->value;		//changes both child nodes so that the smaller one is to the right
				a->rightChild->value = a->leftChild->value;
				a->leftChild->value = aux;
			}
			int aux = a->value;
			a->value = a->rightChild->value;
			a->rightChild->value = aux;
			a = a->rightChild;
		}
	//}
	//catch (...) {}
	return 1;
}
