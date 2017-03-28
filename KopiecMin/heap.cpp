#include "heap.h"




//---------------------------------------


inline int Heap::parentNmbr(int a) { return (a - 1) / 2; }
inline int Heap::leftChildNmbr(int a) { return a * 2 + 1; }
inline int Heap::rightChildNmbr(int a) { return (a * 2) + 2; }

Heap::Heap() {}	//no need?

Heap::Heap(const Heap &src) {
	//Heap *aux;
	//aux = new Heap;
	unsigned int size = src.nodeArray.size();
	nodeArray.resize(size);

	for (unsigned int i = 0; i < size; i++) {
		this->Add(src.nodeArray[i]->value);
	}

}

Heap::~Heap() {

	for (int i = 0; i < this->nodeArray.size(); i++) {
		delete nodeArray[i];

	}
}


Heap& Heap::operator+(int val) {
	
	Heap *aux(this);

	aux->Add(val);

	return *aux;
	
}

Heap& Heap::operator+(Heap &addingHeap) {

	Heap *aux(this);

	aux->Add(addingHeap);

	return *aux;

}

Heap& Heap::operator+=(int val) {
	this->Add(val);
	return *this;
}

Heap& Heap::operator+=(Heap &rs) {
	this->Add(rs);
	return *this;
}

Heap& Heap::operator-(int val) {

	Heap *aux(this);

	aux->Remove(val);

	return *aux;
	
}


// Niepotrzebne?
//Heap& Heap::operator-(Node *a) {	//removes a selected node
//	Heap aux(*this);
//
//	if (aux.Remove(a)) {
//		return aux;
//	}
//	else {
//		cout << "Operator-: error!" << endl;
//		return aux;
//	}
//
//}


Heap& Heap::operator-(Heap &minusHeap) {	//removes the common part of two heaps
	Heap *aux(this);
	
	aux->Remove(minusHeap);
	
	return *aux;
}

Heap& Heap::operator-=(int val) {
	this->Remove(val);
	return *this;
}

Heap& Heap::operator-=(Heap &rs) {
	this->Remove(rs);
	return *this;
}

int Heap::operator[](int n)
{
	return nodeArray[n]->value;
}

Heap& Heap::operator=(Heap &rs) {


	if (this != &rs) {

		while (nodeArray.size()) {
			Remove(nodeArray[0]);
		}
		if (!rs.nodeArray.size()) { return *this; }
		for (int i = 0; i < rs.nodeArray.size(); i++) {
			Add(rs.nodeArray[i]->value);
		}
	}



	return *this;
}






int Heap::Add(int val) {

		unsigned int k = this->nodeArray.size();
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

int Heap::Add(Heap &src) {

		unsigned int n = src.nodeArray.size();
		for (unsigned int i = 0; i < n; i++) {
			this->Add(src.nodeArray[i]->value);
		}
		return 1;
}

int Heap::Remove(Node *a) {

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
		if (aux == a) { delete aux; return 1; }
		if(nodeArray.size() > 0) SwapCond(a);
		return 1;

}

int Heap::Remove(int val) {

		Node *auxnode;
		auxnode = FindNodePriv(val);
		if (!auxnode || (auxnode->value != val)) return 0;
		this->Remove(auxnode);
		return 1;
}

int Heap::Remove(Heap &src) {

		for (int i = 0; i < src.nodeArray.size(); i++) {
			for (int j = 0; j < this->nodeArray.size(); j++) {
				if (src.nodeArray[i]->value == this->nodeArray[j]->value) {
					this->Remove(nodeArray[j]);
					break;	//we want to remove values with 1:1 ratio
				}
			}
		}
		return 1;
}


//Heap test;
// dodanie x elementpw do test
// test = test;



const Node *Heap::FindNode(int val) {	//returns a ptr to first node that value = val
	unsigned int n = nodeArray.size();
	for (unsigned int i = 0; i < n; i++) {
		if (nodeArray[i]->value == val) {
			return nodeArray[i];
		}
	}
	return 0;
}

Node *Heap::FindNodePriv(int val) {	//returns a ptr to first node that value = val
	unsigned int n = nodeArray.size();
	for (unsigned int i = 0; i < n; i++) {
		if (nodeArray[i]->value == val) {
			return nodeArray[i];
		}
	}
	return 0;
}

int Heap::Contains(int val) {
	int sum = 0;
	for (int i = 0; i < nodeArray.size(); i++)
		if (nodeArray[i]->value == val) sum++;

	return sum;
	
}

int Heap::Size() {
	return nodeArray.size();
}

int Heap::SwapCond(Node *a) { //puts selected node in the correct place of the heap 
	while (a && a->parent && a->parent->value > a->value) {	//changes the value between the new object and the parent, 
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


