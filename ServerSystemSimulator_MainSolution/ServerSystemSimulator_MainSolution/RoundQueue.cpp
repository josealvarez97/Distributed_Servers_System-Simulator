#include "RoundQueue.h"



CRoundQueue::CRoundQueue(int size)
{

	this->elements = new int[size];
	this->count = 0;
	this->start = 0;
}


CRoundQueue::~CRoundQueue()
{
}

bool CRoundQueue::Queue(int newElement)
{
	if ((count + 1) < size)
	{
		count++;
		elements[(start + count) % size] = newElement;
		return true;
	}
	else
	{
		return false;
	}


}

int CRoundQueue::Dequeue()
{
	if (count == 0)
		return -1;

	int t = elements[start];
	start = (start + 1) % size;

	count--;

	return t;
}

int CRoundQueue::Peek()
{
	return elements[start];
}
