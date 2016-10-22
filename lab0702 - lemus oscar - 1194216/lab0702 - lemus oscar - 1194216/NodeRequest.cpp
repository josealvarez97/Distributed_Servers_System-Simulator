#include "stdafx.h"
#include "NodeRequest.h"


CNodeRequest::CNodeRequest()
{
	this->next = nullptr;
	this->previous = nullptr;
}

CNodeRequest::CNodeRequest(CRequest Request)
{
	this->next = nullptr;
	this->previous = nullptr;
	this->request = Request;
}


CNodeRequest::~CNodeRequest()
{
}


void CNodeRequest::setRequest(CRequest Request)
{
	this->request = Request;
}


void CNodeRequest::setPrevious(CNodeRequest * p)
{
	this->previous = p;
}


void CNodeRequest::setNext(CNodeRequest * n)
{
	this->next = n;
}

CNodeRequest * CNodeRequest::getPrevious()
{
	return this->previous;
}

CNodeRequest * CNodeRequest::getNext()
{
	return this->next;
}

CRequest CNodeRequest::getRequest()
{
	return this->request;
}