#include "DisplayInformation.h"



CDisplayInformation::CDisplayInformation()
{
}


CDisplayInformation::~CDisplayInformation()
{
}


void CDisplayInformation::DisplayRequestInformation(CRequest request)
{
	cout << "ID: " << request.GetIdentifier() << endl;
	cout << "Tipo de Operación: " << request.GetType_str().c_str() << endl;
	cout << "Procesamiento: " << request.GetProcessingNumbers().c_str() << endl;
	cout << "RAM: " << request.GetRamNumbers().c_str() << endl;
}





void CDisplayInformation::DisplayIdentifier(CRequest request)
{
	cout << "ID: " << request.GetIdentifier() << "("<<request.GetType_str().c_str()<<")" << endl;
}

void CDisplayInformation::DisplayTotals(CRequestStack successfullRequestsStack, CRequestStack failedRequestsStack)
{

	cout << "------REQUESTS EXITOSAS-------" << endl;
	for (int i = successfullRequestsStack.Size(); i > 0; i--)
	{
		DisplayRequestInformation(*successfullRequestsStack.Top());
		successfullRequestsStack.Pop();
	}
	cout << endl << endl;
	cout << "------REQUESTS FALLIDAS-------" << endl;
	for (int i = failedRequestsStack.Size(); i > 0 ; i--)
	{
		DisplayRequestInformation(*failedRequestsStack.Top());
		failedRequestsStack.Pop();
	}



}
