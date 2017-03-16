#include <iostream>

using namespace std;


//----------------------------------
#include "heap.h"



int main() {
	Heap test;	// {1,2,5,5,7}
	test + 2;
	test + 5;
	test + 5;
	test + 7;
	test + 1;
	cout << test;

	Heap test2;	// {2,2,3,4,7}
	test2 + 2;
	test2 + 7;
	test2 + 3;
	test2 + 4;
	test2 + 2;
	cout << test2;

	test2 = test;
	cout << test2;

	test + test2;

	cout << test;

	test - test2;
	//test.Draw();
	cout << test;

	cout << test[1];

	//int *i = new int[1000];
	getchar();
	return 0;
}