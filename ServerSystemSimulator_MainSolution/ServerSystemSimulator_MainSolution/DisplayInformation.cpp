#include "DisplayInformation.h"



CDisplayInformation::CDisplayInformation()
{
}


CDisplayInformation::~CDisplayInformation()
{
}


void CDisplayInformation::DisplayRequestInformation(CRequest request)
{
	cout << "* ID: " << request.GetIdentifier() << endl;
	cout << "	Tipo de Operacion: " << request.GetType_str().c_str() << endl;
	cout << "	Procesamiento: " << request.GetProcessingNumbers().c_str() << endl;
	cout << "	RAM: " << request.GetRamNumbers().c_str() << endl;
}





void CDisplayInformation::DisplayIdentifier(CRequest request)
{
	cout << "ID: " << request.GetIdentifier() << "(" << request.GetType_str().c_str() << ")" << endl;
}

void CDisplayInformation::DisplayTotals(CRequestStack successfullRequestsStack, CRequestStack failedRequestsStack)
{

	cout << "------------------------REQUESTS EXITOSAS------------------------" << endl;
	for (int i = successfullRequestsStack.Size(); i > 0; i--)
	{
		DisplayRequestInformation(*successfullRequestsStack.Top());
		successfullRequestsStack.Pop();
	}
	cout << endl << endl;
	cout << "------------------------REQUESTS FALLIDAS------------------------" << endl;
	for (int i = failedRequestsStack.Size(); i > 0; i--)
	{
		DisplayRequestInformation(*failedRequestsStack.Top());
		failedRequestsStack.Pop();
	}



}

void CDisplayInformation::DisplaySuccesfullRequestsOnThisTick(CRequestStack successfullRequestsStack, int previousSuccesfullRequests)
{
	cout << "## REQUESTS COMPLETADAS Y ENVIADAS A PILA DE EXITO EN ESTE TICK ##" << endl;
	if (successfullRequestsStack.Size() != previousSuccesfullRequests)
		for (int i = successfullRequestsStack.Size(); i > previousSuccesfullRequests; i--)
		{
			cout << "- "; DisplayIdentifier(*successfullRequestsStack.Top());
			successfullRequestsStack.Pop();
		}
	else
		cout << "(No se completo ninguna peticion en este tick)" << endl;
	cout << endl;
}

//void CDisplayInformation::DisplayServerState(CServer server)
//{
//	server.
//
//
//}
