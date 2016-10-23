#include "Stack.h"


CStack::CStack()
{
}


CStack::~CStack()
{
}

int CStack::Size()
{
	return this->counter;
}

void CStack::Push(int number)
{
	list.Add(number);
	counter++;
}

int CStack::Pop()
{
	if (list.Size() != 0)
	{
		int element = list.LastElement();
		list.RemoveTail();
		counter--;
		return element;
	}

	return -1;

}

int CStack::Top()
{
	if (list.Size() != 0)
		return list.LastElement();
	return -1;
}
