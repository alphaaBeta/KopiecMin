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
	test.Draw();

	Heap test2;	// {2,2,3,4,7}
	test2 + 2;
	test2 + 7;
	test2 + 3;
	test2 + 4;
	test2 + 2;

	test2.Draw();

	test + test2;

	test.Draw();

	test - test2;
	test.Draw();

	//int *i = new int[1000];
	getchar();
	return 0;
}