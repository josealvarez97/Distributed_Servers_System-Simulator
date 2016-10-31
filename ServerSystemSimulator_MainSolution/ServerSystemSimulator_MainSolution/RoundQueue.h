#pragma once
class CRoundQueue
{
protected:
	int size;
	int* elements;
	int count;
	int start;
public:
	CRoundQueue(int size);
	~CRoundQueue();

	bool Queue(int newElement);

	int Dequeue();
	int Peek();

	int Count() { return count; }
	


};

