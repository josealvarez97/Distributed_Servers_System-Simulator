#include "LoadBalancer.h"



CLoadBalancer::CLoadBalancer(CServer* server1, CServer* server2, CServer* server3)
{
	this->server1 = server1;
	this->server2 = server2;
	this->server3 = server3;

	this->currentFirstRequest = CRequest();
	this->currentSecondRequest = CRequest();
	this->currentThirdRequest = CRequest();
}


CLoadBalancer::~CLoadBalancer()
{
}


void CLoadBalancer::TakeRequestFromRequestQueue(CRequest request, int currentRequestPlace)
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


CRequest CLoadBalancer::GetCurrentFirstRequest()
{
	return this->currentFirstRequest;
}



CRequest CLoadBalancer::GetCurrentSecondRequest()
{
	return this->currentSecondRequest;
}


CRequest CLoadBalancer::GetCurrentThirdRequest()
{
	return this->currentThirdRequest;
}


bool CLoadBalancer::TryToAssignRequestToAServer(CRequest request)
{
	bool succesfullAssignation = false;

	if (this->server1->AskAvailability(request.GetProcessingNumbers().length(), request.GetRamNumbers().length()) == true
		&& succesfullAssignation != true)
	{
		this->server1->ReceiveRequest(request);
		succesfullAssignation = true;
	}
	else if (this->server2->AskAvailability(request.GetProcessingNumbers().length(), request.GetRamNumbers().length()) == true
		&& succesfullAssignation != true)
	{
		this->server2->ReceiveRequest(request);
		succesfullAssignation = true;
	}
	else if (this->server3->AskAvailability(request.GetProcessingNumbers().length(), request.GetRamNumbers().length()) == true
		&& succesfullAssignation != true)
	{
		this->server3->ReceiveRequest(request);
		succesfullAssignation = true;
	}



	return succesfullAssignation;
}
