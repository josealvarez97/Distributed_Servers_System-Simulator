#include "stdafx.h"
#include "DNode.h"


CNode::CNode()
{
	this->previous = nullptr;
	this->value = 0;
	this->next = nullptr;
}

CNode::CNode(int number)
{
	this->previous = nullptr;
	this->value = number;
	this->next = nullptr;
}

void CNode::setValue(int number)
{
	this->value = number;
}

void CNode::setPrevious(CNode *p)
{
	this->previous = p;
}

void CNode::setNext(CNode *p)
{
	this->next = p;
}

CNode * CNode::getPrevious()
{
	return this->previous;
}

CNode *CNode::getNext()
{
	return this->next;

}


CNode::~CNode()
{
}


int CNode::getValue()
{
	return this->value;
}
