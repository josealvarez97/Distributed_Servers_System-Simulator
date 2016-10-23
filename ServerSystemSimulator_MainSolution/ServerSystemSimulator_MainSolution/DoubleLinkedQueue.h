#pragma once
#include "DoubleLinkedList.h"
class CDoubleLinkedQueue
{
private:
	DoubleLinkedList queue;
public:
	CDoubleLinkedQueue();
	~CDoubleLinkedQueue();

	void Queue(int number);
	int Dequeue();
	int Size();
	void SetMAX_SIZE(int maxSize);
	int GetMAX_Size();

};

