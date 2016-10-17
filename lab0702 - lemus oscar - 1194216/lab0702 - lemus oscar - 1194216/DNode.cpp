#include "stdafx.h"
#include "DNode.h"


DNode::DNode()
{
	this->previous = nullptr;
	this->value = 0;
	this->next = nullptr;
}

DNode::DNode(int number)
{
	this->previous = nullptr;
	this->value = number;
	this->next = nullptr;
}

void DNode::setValue(int number)
{
	this->value = number;
}

void DNode::setPrevious(DNode *p)
{
	this->previous = p;
}

void DNode::setNext(DNode *p)
{
	this->next = p;
}

DNode * DNode::getPrevious()
{
	return this->previous;
}

DNode *DNode::getNext()
{
	return this->next;

}


DNode::~DNode()
{
}


int DNode::getValue()
{
	return this->value;
}
