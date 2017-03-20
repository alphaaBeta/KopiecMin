#include "HeapTester.h"

#include <assert.h>

bool HeapTester::DoTests()
{
	assert(AddTest() == 1);
	cout << endl;
	assert(AssignAddTest() == 1);
	cout << endl;
	assert(RemoveTest() == 1);
	cout << endl;
	assert(HeapAddRemoveTest() == 1);
	cout << endl;
	return true;
}

bool HeapTester::AssignAddTest() {
	Heap testHeap;
	testHeap = testHeap + 2;
	testHeap = testHeap + 5;
	testHeap = testHeap + (-10);
	return (testHeap.Contains(2) &&
		testHeap.Contains(5) &&
		testHeap.Contains(-10) &&
		(testHeap.Size() == 3)
		);
}


bool HeapTester::AddTest() {
	Heap testHeap;
	testHeap += 2;
	testHeap += 5;
	testHeap += 12;
	testHeap += 2;
	testHeap += -10;
	return ((testHeap.Contains(2) == 2) &&
		testHeap.Contains(5) &&
		testHeap.Contains(12) &&
		testHeap.Contains(-10) &&
		(testHeap.Size() == 5
			));
}

bool HeapTester::RemoveTest() {
	Heap testHeap;
	testHeap += 2;
	testHeap += 3;
	testHeap -= 3;
	testHeap -= 3;
	testHeap -= 2;
	return (testHeap.Size() == 0);
}

bool HeapTester::HeapAddRemoveTest() {
	Heap mainHeap, addHeap, minusHeap;
	addHeap += 5;
	addHeap += 2;
	addHeap += 0;
	addHeap += 5;
	mainHeap = mainHeap + addHeap;
	mainHeap += addHeap;
	minusHeap = addHeap;
	mainHeap -= minusHeap;
	return ((mainHeap.Contains(5) == 2) &&
		mainHeap.Contains(0) &&
		mainHeap.Contains(2) &&
		(mainHeap.Size() == 4)
		);
}