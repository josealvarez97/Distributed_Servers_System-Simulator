#pragma once
#include "Request.h"
#include "Server.h"
class CLoadBalancer
{
private:
	CRequest *currentFirstRequest, *currentSecondRequest, *currentThirdRequest;
	CServer *server1, *server2, *server3;

public:

	CLoadBalancer(CServer* server1, CServer* server2, CServer* server3);
	~CLoadBalancer();



	void TakeRequestFromRequestQueue(CRequest *request, int currentRequestPlace);
	CRequest* GetCurrentFirstRequest();
	CRequest* GetCurrentSecondRequest();
	CRequest* GetCurrentThirdRequest();
	bool TryToAssignRequestToAServer(CRequest* request);
};

