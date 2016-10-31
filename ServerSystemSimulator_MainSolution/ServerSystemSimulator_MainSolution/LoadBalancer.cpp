#include "LoadBalancer.h"



CLoadBalancer::CLoadBalancer(CServer* server1, CServer* server2, CServer* server3)
{
	this->server1 = server1;
	this->server2 = server2;
	this->server3 = server3;

	this->currentFirstRequest = nullptr;
	this->currentSecondRequest = nullptr;
	this->currentThirdRequest = nullptr;

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

	if (request != nullptr)
		if (this->server1->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true && this->server1->IsWorking() == false)
		{
			this->server1->ReceiveRequest(request);
			this->lastServerAssignation = 1;
			succesfullAssignation = true;
		}
		else if (this->server2->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true && this->server2->IsWorking() == false )
		{
			this->server2->ReceiveRequest(request);
			this->lastServerAssignation = 2;
			succesfullAssignation = true;
		}
		else if (this->server3->AskAvailability(request->GetProcessingNumbers().length(), request->GetRamNumbers().length()) == true
			&& succesfullAssignation != true && this->server3->IsWorking() == false)
		{
			this->server3->ReceiveRequest(request);
			this->lastServerAssignation = 3;
			succesfullAssignation = true;
		}



	return succesfullAssignation;
}

int CLoadBalancer::GetlastServerAssignation()
{
	return this->lastServerAssignation;
}
