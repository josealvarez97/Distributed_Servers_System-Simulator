#pragma once
#include "DoubleLinkedList.h"
class CStack
{
private:
	DoubleLinkedList list;
	int counter;
public:
	CStack();
	~CStack();
	int Size();
	void Push(int number);
	int Pop();
	int Top();

	
};

