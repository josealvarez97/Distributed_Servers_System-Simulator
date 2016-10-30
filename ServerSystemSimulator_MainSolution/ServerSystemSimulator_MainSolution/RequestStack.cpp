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
	if ( Size() > 1)
	{
		//CNodeRequest * Temp = nullptr;
		//Temp = this->tail;

		this->tail = tail->getPrevious();
		this->tail->setNext(nullptr);
		//delete Temp; // Lo eliminamos para que no ocupe espacio en memoria
		this->counter--;
	}
	else if (Size() == 1)
	{
		this->tail = nullptr;
		this->head = nullptr;
		counter--;
	}
}


void CRequestStack::Push(CRequest* request)
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


CRequest* CRequestStack::Top()
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