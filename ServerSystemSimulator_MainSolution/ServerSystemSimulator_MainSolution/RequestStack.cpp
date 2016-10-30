#include "RequestStack.h"



CRequestStack::CRequestStack()
{
	this->counter = 0;
	
}


CRequestStack::~CRequestStack()
{
}




void CRequestStack::Pop()
{
	if ( Size() > 0)
	{
		CNodeRequest * Temp = new CNodeRequest();
		Temp = this->tail;

		this->tail = tail->getPrevious();
		this->tail->setNext(nullptr);
		delete Temp; // Lo eliminamos para que no ocupe espacio en memoria
		this->counter--;
	}
}


void CRequestStack::Push(CRequest request)
{
	if (this->head)
	{
		CNodeRequest * n = new CNodeRequest(request);
		this->tail->setNext(n);
		n->setPrevious(this->tail);
		this->tail = n;
		this->counter++;
	}
	else
	{
		CNodeRequest *n = new CNodeRequest(request);
		this->head = n;
		this->tail = n;
		this->counter++;
	}
}


CRequest CRequestStack::Top()
{
	if (Size() > 0)
	{
		return this->tail->getRequest();
	}
}

int CRequestStack::Size()
{
	return this->counter;
}