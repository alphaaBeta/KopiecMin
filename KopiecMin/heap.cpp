#include "heap.h"




//---------------------------------------



inline int Heap::parentNmbr(int a) { return (a - 1) / 2; }
inline int Heap::leftChildNmbr(int a) { return a * 2 + 1; }
inline int Heap::rightChildNmbr(int a) { return (a * 2) + 2; }


int Heap::operator+(int val) {
	unsigned int &k = numberOfNodes;
	Node *aux;
	aux = new Node;

	if (k == 0) {
		//in case of adding a first node, set all pointers to 0
		
		aux->value = val;
		aux->parent = 0;
		aux->leftChild = 0;
		aux->rightChild = 0;

		nodeArray.push_back(aux);

		numberOfNodes++;
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
	
	
	numberOfNodes++;
	return 1;

	
}

int Heap::operator-(int val) {
	Node *aux;
	aux = SearchHeap(val);
		while (aux) {
			operator-(aux);
			aux = SearchHeap(val);
		}
		return 1;
	
}

int Heap::operator+(Heap &addingHeap) {
	int n = addingHeap.nodeArray.size();
	for (int i = 0; i < n; i++) {
		operator+(addingHeap.nodeArray[i]->value);
	}
	return 1;

}

int Heap::operator-(Node *a) {
	Node *aux;
	//aux = &nodeArray[numberOfNodes - 1];
	aux = nodeArray[numberOfNodes - 1];
	if (aux->parent && aux->parent->leftChild == aux) {	//removing connections
		aux->parent->leftChild = 0;
	}
	else {
		aux->parent->rightChild = 0;
	}
	a->value = aux->value;
	nodeArray.pop_back();
	numberOfNodes--;
	SwapCond(a);
	return 1;
}

int Heap::operator-(Heap &minusHeap) {
	for (int i = 0; i < minusHeap.nodeArray.size(); i++) {
		for (int j = 0; j < nodeArray.size(); j++) {
			if (minusHeap.nodeArray[i]->value == nodeArray[j]->value) {
				operator-(nodeArray[j]);
				break;	//we want to remove values with 1:1 ratio
			}
		}
	}
	return 1;
}

Node *Heap::SearchHeap(int val) {
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

	return 0;
}



void Heap::Draw(){
	int n = nodeArray.size();
	int i = 0;
	while (i < n) {
		cout << nodeArray.at(i)->value<< " ";
		i++;
	}
	cout <<endl << numberOfNodes<< endl;
}
