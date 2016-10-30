#pragma once
#include "Request.h"

class CNodeRequest
{
public:
	CNodeRequest();
	CNodeRequest(CRequest* Request);
	~CNodeRequest();
	void setRequest(CRequest* Request);
	void setPrevious(CNodeRequest * p);
	void setNext(CNodeRequest * n);
	CNodeRequest *getPrevious();
	CNodeRequest *getNext();
	CRequest* getRequest();
private:
	CNodeRequest * next;
	CNodeRequest * previous;
	CRequest* request;

};

