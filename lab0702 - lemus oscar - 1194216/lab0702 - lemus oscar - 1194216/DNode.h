#pragma once
class DNode
{
public:
	DNode();
	DNode(int number);
	~DNode();

	void setValue(int number);
	void setPrevious(DNode *p);
	void setNext(DNode *p);
	DNode *getPrevious();
	DNode *getNext();

private:
	DNode * previous;
	int value;
	DNode * next;
public:
	int getValue();
};

