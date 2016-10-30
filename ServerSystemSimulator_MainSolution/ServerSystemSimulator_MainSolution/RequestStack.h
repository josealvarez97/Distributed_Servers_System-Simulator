#pragma once
#include "NodeRequest.h"
#include "Request.h"
class CRequestStack
{
public:
	CRequestStack();
	~CRequestStack();
	void Pop();
	int Size();
	void Push(CRequest *request);
	CRequest* Top();
private:
	CNodeRequest * head;
	CNodeRequest * tail;
	int counter;
public:

};

