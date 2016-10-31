#include "LoadBalancer.h"



CLoadBalancer::CLoadBalancer(CServer* server1, CServer* server2, CServer* server3)
{
	this->server1 = server1;
	this->server2 = server2;
	this->server3 = server3;

	this->currentFirstRequest = nullptr;
	this->currentSecondRequest = nullptr;
	this->currentThirdRequest = nullptr;


	this->serverRankingArray[0] = server1;
	this->serverRankingArray[1] = server2;
	this->serverRankingArray[2] = server3;
	this->lastServerAssignation = 0;
}


CLoadBalancer::~CLoadBalancer()
{
}


void CLoadBalancer::TakeRequestFromRequestQueue(CRequest* request, int currentRequestPlace)
{
	switch (currentRequestPlace)
	{
	case 1:
		this->currentFirstRequest = request;
		break;
	case 2:
		this->currentSecondRequest = request;
		break;
	case 3:
		this->currentThirdRequest = request;
		break;
	default:
		break;
	}


}


CRequest* CLoadBalancer::GetCurrentFirstRequest()
{
	return this->currentFirstRequest;
}



CRequest* CLoadBalancer::GetCurrentSecondRequest()
{
	return this->currentSecondRequest;
}


CRequest* CLoadBalancer::GetCurrentThirdRequest()
{
	return this->currentThirdRequest;
}


bool CLoadBalancer::TryToAssignRequestToAServer(CRequest* request)
{
	bool succesfullAssignation = false;

	// serverRanking means how fucked up is a server

	SetServersCurrentRank(); // Reset the ranking. Check out "Optimizations" in readme

	if (request != nullptr)
		if (this->serverRankingArray[0]/*least Ranked (best condition)*/->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true)
		{
			this->serverRankingArray[0]->ReceiveRequest(request);
			this->lastServerAssignation = serverRankingArray[0]->GetServerID();
			succesfullAssignation = true;
		}
		else if (this->serverRankingArray[1]/*middle Ranked*/->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true)
		{
			this->serverRankingArray[1]->ReceiveRequest(request);
			this->lastServerAssignation = serverRankingArray[1]->GetServerID();
			succesfullAssignation = true;
		}
		else if (this->serverRankingArray[2]/*higher Ranked (worst condition)*/->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true)
		{
			this->serverRankingArray[2]->ReceiveRequest(request);
			this->lastServerAssignation = serverRankingArray[2]->GetServerID();
			succesfullAssignation = true;
		}



	return succesfullAssignation;
}

int CLoadBalancer::GetlastServerAssignation()
{
	return this->lastServerAssignation;
}

void CLoadBalancer::SetServersCurrentRank()
{
	// Sort of current server ranking
	int n = 2;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			// 0 position is least, 3 is most
			if (this->serverRankingArray[i]->GetServerRank() >= this->serverRankingArray[i + 1]->GetServerRank())
			{
				swap(this->serverRankingArray[i], this->serverRankingArray[i + 1]);
			}

		}
	}



}
