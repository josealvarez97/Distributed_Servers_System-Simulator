#pragma once
#include "DoubleLinkedList.h"
#include "DoubleLinkedQueue.h"
#include "RequestStack.h"
#include "RequestQueue.h"
#include "Request.h"
#include "HardDisk.h"
using namespace std;
class CServer
{
private: //Attributes
	CDoubleLinkedQueue serverProcessingQueue;
	DoubleLinkedList serverRAM;
	int operationsPerTick;
	CRequestStack* sucessfullRequestsStack;
	CRequestQueue* serverRequestsQueue;
	int CurrentRequestRAMNumbers;
	int CurrentRequestProcessingNumbersLeft;
	CHardDisk* hardDisk;

private: //Methods
	int RamFreeSpace();
	int ProcessingQueueFreeSpace();
	void OperateRam(int currentRequestRamNumbers, typeOfOperation type);

public:
	CServer(int processingSize, int ramSize, int operationsPerTick, CRequestStack* succesfullRequestsStack, CHardDisk* hardDisk);
	~CServer();

	void Work();
	bool AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary);
	void ReceiveRequest(CRequest* request);

	void PrintQueueState();
	void PrintServerInfo();
	bool IsWorking();


};

