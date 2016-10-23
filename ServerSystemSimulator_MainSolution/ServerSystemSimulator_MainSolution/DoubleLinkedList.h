#pragma once
#include "DNode.h"

class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool Add(int number);
	bool InsertFirst(int number);
	int FirstElement();
	int Size();
	int LastElement();
	bool RemoveHead();
	int ItemAtIndex(int index);
	bool InsertBeforeOf(int number, int position);
private:
	CNode *head;
	CNode *tail;
	int counter;
public:
	bool InsertAfterOf(int number, int position);
	int IndexOf(int value);
	bool RemoveTail();
	bool RemoveNodeIn(int position);
};

