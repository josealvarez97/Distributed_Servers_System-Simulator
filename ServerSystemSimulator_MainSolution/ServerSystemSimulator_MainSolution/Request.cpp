#include "Request.h"


CRequest::CRequest()
{
	this->completed = false;
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
	this->numberOfProcessingSpacesNeeded = numbers.length();
}

void CRequest::SetRamNumbers(string numbers)
{
	this->ramNumbers = numbers;
	this->numberOfRamSpacesNeeded = numbers.length();
}

typeOfOperation CRequest::GetTypeOfOperation()
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

bool CRequest::IsComplete()
{
	return this->completed;
}

int CRequest::GetResult()
{
	return this->result;
}

void CRequest::SetResult(int number)
{
	this->result = number;
}

void CRequest::SetComplete(bool value)
{
	this->completed = value;
}

