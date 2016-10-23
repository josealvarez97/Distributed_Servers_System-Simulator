#include "Server.h"




int CServer::RamFreeSpace()
{
	return this->serverRAM.GetMAX_SIZE() - this->serverRAM.Size();
}

int CServer::ProcessingQueueFreeSpace()
{
	return this->serverProcessingQueue.GetMAX_Size() - this->serverProcessingQueue.GetMAX_Size();
}

CServer::CServer(int processingSize, int ramSize, int operationsPerTick, CRequestStack * succesfullRequestsStack)
{
	this->serverProcessingQueue.SetMAX_SIZE(processingSize);
	this->serverRAM.SetMAX_SIZE(ramSize);
	this->operationsPerTick = operationsPerTick;
	this->sucessfullRequestsStack = succesfullRequestsStack;
}

CServer::~CServer()
{
}

void CServer::Work()
{
	// Necesitamos algoritmos y formas de guardar la informacion de las peticioenes...
}

bool CServer::AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary)
{
	if (this->ProcessingQueueFreeSpace() >= processingSpaceNecessary
		&& this->RamFreeSpace() >= ramSpaceNecessary)
		return true;
	else
		return false;
}
