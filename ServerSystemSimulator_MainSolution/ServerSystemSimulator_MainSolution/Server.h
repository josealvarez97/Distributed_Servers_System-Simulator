#pragma once
#include "DoubleLinkedList.h"
#include "DoubleLinkedQueue.h"
#include "RequestStack.h"
using namespace std;
class CServer
{
private: //Attributes
	CDoubleLinkedQueue serverProcessingQueue;
	DoubleLinkedList serverRAM;
	int operationsPerTick;
	CRequestStack* sucessfullRequestsStack;
private: //Methods
	int RamFreeSpace();
	int ProcessingQueueFreeSpace();

public:
	CServer(int processingSize, int ramSize, int operationsPerTick, CRequestStack* succesfullRequestsStack);
	~CServer();

	void Work();
	bool AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary);


};

