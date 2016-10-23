#pragma once
#include "NodeRequest.h"
class CRequestQueue
{
public:
	CRequestQueue();
	~CRequestQueue();
	bool Queue(CRequest Request);
	int Size();
	CRequest* Dequeue();
private:
	CNodeRequest * head;
	CNodeRequest * tail;
	int counter;
};

