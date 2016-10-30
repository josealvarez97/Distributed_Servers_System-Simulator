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

bool CRequestQueue::Queue(CRequest *Request)
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

CRequest* CRequestQueue::Dequeue()
{
	CRequest *Temp;

	if (counter > 1)
	{
		Temp = this->head->getRequest();
		this->head = this->head->getNext();
		this->head->setPrevious(nullptr);
		counter--;

		return Temp;
	}
	else if (counter == 1)
	{
		Temp = this->head->getRequest();
		this->head = nullptr;
		this->tail = nullptr;
		counter--;
		return Temp;
	}
	else
	{
		return nullptr;
	}
}


CRequest* CRequestQueue::ReturnHead()
{
	//if (Size() > 0)
	//{


	return this->head->getRequest();
	/*}*/

}

//CRequest * CRequestQueue::ReturnHeadPtr()
//{
//	return this->head->getRequest();
//}

