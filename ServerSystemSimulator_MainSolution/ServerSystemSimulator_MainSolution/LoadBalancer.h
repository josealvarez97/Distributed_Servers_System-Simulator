#pragma once
#include "Request.h"
#include "Server.h"
class CLoadBalancer
{
private:
	CRequest *currentFirstRequest, *currentSecondRequest, *currentThirdRequest;
	CServer *server1, *server2, *server3;


	CServer *serverRankingArray[3];	// serverRanking means how fucked up a server is
	int lastServerAssignation;

public:

	CLoadBalancer(CServer* server1, CServer* server2, CServer* server3);
	~CLoadBalancer();



	void TakeRequestFromRequestQueue(CRequest *request, int currentRequestPlace);
	CRequest* GetCurrentFirstRequest();
	CRequest* GetCurrentSecondRequest();
	CRequest* GetCurrentThirdRequest();
	bool TryToAssignRequestToAServer(CRequest* request);
	int GetlastServerAssignation();
	void SetServersCurrentRank();
};

