#include "Request.h"


CRequest::CRequest()
{
}


CRequest::~CRequest()
{
}

void CRequest::SetTypeOfOperation(typeOfOperation Type)
{
	this->operationType = Type;
}

void CRequest::SetProcessingNumbers(string numbers)
{
	this->processingQueueNumbers = numbers;
}

void CRequest::SetRamNumbers(string numbers)
{
	this->ramNumbers = numbers;
}

int CRequest::GetTypeOfOperation()
{
	return operationType;
}

string CRequest::GetProcessingNumbers()
{
	return processingQueueNumbers;
}

string CRequest::GetRamNumbers()
{
	return ramNumbers;
}

void CRequest::SetIdentifier(char identifier)
{
	this->requestIdentifier = identifier;
}

char CRequest::GetIdentifier()
{
	return this->requestIdentifier;
}
