#include "RequestStack.h"



CRequestStack::CRequestStack()
{
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

		this->tail = Temp->getPrevious();
		this->tail->setNext(nullptr);
		delete Temp; // Lo eliminamos para que no ocupe espacio en memoria
		counter--;
	}
}


void CRequestStack::Push(CRequest* request)
{
	if (this->head)
	{
		CNodeRequest * n = new CNodeRequest(*request);
		this->head->setPrevious(n);
		n->setNext(this->head);
		this->head = n;
		counter++;
	}
	else
	{
		CNodeRequest *n = new CNodeRequest(*request);
		this->head = n;
		this->tail = n;
		counter++;
	}
}


CRequest CRequestStack::Peek()
{
	if (Size() > 0)
	{
		CNodeRequest* Temp;
		Temp = this->tail;

		return (Temp->getRequest());
	}
}

int CRequestStack::Size()
{
	return this->counter;
}