#include "heap.h"

int square(int a, int power) {
	int ret = 0;
	while (power) {
		ret *= a;
		power--;
	} 
}

heap::heap() {
	nodeArray = 0;
}

heap::~heap() {
	delete[] nodeArray;

}

int heap::operator+(int value) {
	numberOfNodes++;
	if (nodeArray == 0) {
		nodeArray = new node[numberOfNodes];
	}
}
