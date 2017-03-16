#pragma once


class Node
{
public:
	Node *parent, *leftChild, *rightChild;
	int value;
	/*
	friend ostream& operator<<(ostream &os, const Node &wez) {
		os << wez.value;
		return os;
	}*/
};

