#include "heap.h"




//---------------------------------------



inline int Heap::parentNmbr(int a) { return (a - 1) / 2; }
inline int Heap::leftChildNmbr(int a) { return a * 2 + 1; }
inline int Heap::rightChildNmbr(int a) { return (a * 2) + 2; }


Heap& Heap::operator+(int val) {
	unsigned int k = nodeArray.size();
	Node *aux;
	aux = new Node;

	if (k == 0) {
		//in case of adding a first node, set all pointers to 0
		
		aux->value = val;
		aux->parent = 0;
		aux->leftChild = 0;
		aux->rightChild = 0;

		nodeArray.push_back(aux);

		return 1;
		
	}
	else {
		
		aux->value = val;
		aux->parent = nodeArray[parentNmbr(k)];

		if (aux->parent->leftChild == 0) {	//checking which child of the parent is empty
			aux->parent->leftChild = aux;
		}
		else {
			aux->parent->rightChild = aux;
		}

		aux->leftChild = 0;
		aux->rightChild = 0;
		nodeArray.push_back(aux);
		SwapCond(nodeArray[k]);

	}
	
	
	return 1;

	
}

Heap& Heap::operator+(Heap &addingHeap) {
	int n = addingHeap.nodeArray.size();
	for (int i = 0; i < n; i++) {
		this->operator+(addingHeap.nodeArray[i]->value);
	}
	return 1;

}

int Heap::Add(int) {

}

Heap& Heap::operator-(int val) {
	const Node *aux;
	aux = FindNode(val);
		while (aux) {
			this->operator-(aux);	//TODO: odejmowanie
			aux = FindNode(val);
		}
		return 1;
	
}



Heap& Heap::operator-(Node *a) {	//removes a selected node
	Node *aux;
	aux = nodeArray[nodeArray.size() - 1];

	if (aux->parent && aux->parent->leftChild == aux) {	//removing connections
		aux->parent->leftChild = 0;
	}
	else if (aux->parent && aux->parent->rightChild) {
		aux->parent->rightChild = 0;
	}

	a->value = aux->value;
	nodeArray.pop_back();
	SwapCond(a);
	return 1;
}

Heap& Heap::operator-(Heap &minusHeap) {	//removes the common part of two heaps
	for (int i = 0; i < minusHeap.nodeArray.size(); i++) {
		for (int j = 0; j < nodeArray.size(); j++) {
			if (minusHeap.nodeArray[i]->value == nodeArray[j]->value) {
				this->operator-(nodeArray[j]);
				break;	//we want to remove values with 1:1 ratio
			}
		}
	}
	return 1;
}

int Heap::operator[](int n)
{
	return nodeArray[n]->value;
}

//Heap test;
// dodanie x elementpw do test
// test = test;

Heap& Heap::operator=(Heap &rs) {

	while (nodeArray.size()) {
		operator-(nodeArray[0]);
	}
	for (int i = 0; i < rs.nodeArray.size(); i++) {
		operator+(rs.nodeArray[i]->value);
	}

	return 1;
}


const Node *Heap::FindNode(int val) {	//returns a ptr to first node that value = val
	int n = nodeArray.size();
	for (int i = 0; i < n; i++) {
		if (nodeArray[i]->value == val) {
			return nodeArray[i];
		}
	}
	return 0;
}


int Heap::SwapCond(Node *a) { //puts selected node in the correct place of the heap 
	while (a->parent && a->parent->value > a->value) {	//changes the value between the new object and the parent, 
		int aux = a->value;													//as long as the parent doesn't fit criteria
		a->value = a->parent->value;
		a->parent->value = aux;
		a = a->parent;
	}
	
	while ((a->leftChild && a->leftChild->value < a->value) ||
		(a->rightChild && a->rightChild->value < a->value)) {

		if (a->rightChild) {
			
			if (a->rightChild->value < a->leftChild->value) {
				int aux = a->rightChild->value;
				a->rightChild->value = a->value;
				a->value = aux;
				a = a->rightChild;
				continue;
			}
			else {
				int aux = a->leftChild->value;
				a->leftChild->value = a->value;
				a->value = aux;
				a = a->leftChild;
				continue;
			}
		}
		
		int aux = a->leftChild->value;
		a->leftChild->value = a->value;
		a->value = aux;
		a = a->leftChild;

	}

	return 1;
}


