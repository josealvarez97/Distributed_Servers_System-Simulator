#pragma once
class CNode
{
public:
	CNode();
	CNode(int number);
	~CNode();

	void setValue(int number);
	void setPrevious(CNode *p);
	void setNext(CNode *p);
	CNode *getPrevious();
	CNode *getNext();
	int getValue();

private:
	CNode * previous;
	int value;
	CNode * next;


};

