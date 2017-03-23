#include <iostream>

//using namespace std;


//----------------------------------
#include "heap.h"
#include "HeapTester.h"



int main() {
	HeapTester test1;
	cout << test1.DoTests(); 
	
	Heap test0, test2;
	test0 += 2;
	test0 += 3;
	test2+= 4;
	test2+= 5;
	cout << test0 << endl << test2 << endl;
	test0 = test2;
	cout << test0;

	getchar();
	return 0;
}