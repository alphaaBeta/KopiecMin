#include <iostream>

using namespace std;


//----------------------------------
#include "heap.h"
#include "HeapTester.h"


//bool addTest() {
//	Heap test1; 
//	test1 += 2;
//	test1 += 5;
//	return (test1.contains(2) && test1.contains(5) && test1.size() == 2);
//}

int main() {
	/*
	Heap test;	// {1,2,5,5,7}
	test = test + 2;
	test = test + 5;
	test = test + 5;
	test = test + 7;
	test = test + 1;
	cout << test;

	Heap test2;	// {2,2,3,4,7}
	test2 += 2;
	test2 += 7;
	test2 += 3;
	test2 += 4;
	test2 += 2;
	cout << test2;

	test2 = test;
	cout << test2;

	test += test2;

	cout << test;

	test -= test2;
	//test.Draw();
	cout << test;

	cout << test[1];
	*/
	HeapTester test1;
	cout << test1.DoTests();

	//int *i = new int[1000];
	getchar();
	return 0;
}