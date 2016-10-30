#include "DoubleLinkedQueue.h"



CDoubleLinkedQueue::CDoubleLinkedQueue()
{
}


CDoubleLinkedQueue::~CDoubleLinkedQueue()
{
}

void CDoubleLinkedQueue::Queue(int number)
{
	this->queue.Add(number);
}

int CDoubleLinkedQueue::Dequeue()
{
	if (Size() > 0)
	{
		int element = queue.FirstElement();
		queue.RemoveHead();
		return element;
	}
	else 
	{
		return -1;
	}


}

int CDoubleLinkedQueue::Size()
{
	return queue.Size();
}

int CDoubleLinkedQueue::GetMAX_Size()
{
	return this->queue.GetMAX_SIZE();
}

void CDoubleLinkedQueue::SetMAX_SIZE(int maxSize)
{
	this->queue.SetMAX_SIZE(maxSize);
}
