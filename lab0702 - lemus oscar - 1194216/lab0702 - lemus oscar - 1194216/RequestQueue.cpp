#include "stdafx.h"
#include "RequestQueue.h"
#include "Request.h"


CRequestQueue::CRequestQueue()
{
	this->head = nullptr;
	this->tail = nullptr;
	counter = 0;
}


CRequestQueue::~CRequestQueue()
{
	while (this->head)
	{
		// pasar al siguiente
		this->head = this->head->getNext();


		// El anterior tiene algo diferente de null
		if (this->head->getPrevious())
		{
			delete this->head->getPrevious();
		}
	}
	delete this->tail;
}

bool CRequestQueue::Queue(CRequest Request)
{
	if (this->head)
	{
		CNodeRequest *n = new CNodeRequest(Request);
		n->setPrevious(this->tail);
		this->tail->setNext(n);
		this->tail = n;
		counter++;
		//agregar al final

	}
	else
	{
		CNodeRequest  *n = new CNodeRequest(Request);
		this->head = n;
		this->tail = n;
		counter++;
		//agregar al inicio
	}
	return false;
}

int CRequestQueue::Size()
{
	return this->counter;
}

bool CRequestQueue::Dequeue()
{
	if (counter > 0)
	{
		CNodeRequest * Temp = new CNodeRequest();
		Temp = this->head;

		this->head = Temp->getNext();
		this->head->setPrevious(nullptr);
		counter--;
		delete Temp; // Lo eliminamos para que no ocupe espacio en memoria
		return true;
	}
	return false;
}
