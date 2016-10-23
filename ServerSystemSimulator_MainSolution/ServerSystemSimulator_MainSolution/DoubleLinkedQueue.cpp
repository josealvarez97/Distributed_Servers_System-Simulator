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
	int element = queue.LastElement();
	queue.RemoveTail();
	return element;
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
