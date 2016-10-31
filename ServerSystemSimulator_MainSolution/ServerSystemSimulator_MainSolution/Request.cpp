#include "Request.h"


CRequest::CRequest()
{
	this->completed = false;

	this->requestIdentifier = -1;
	this->operationType = NOTYPE;
	this->ramNumbers = "-1";
	this->processingQueueNumbers = "-1";
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

void CRequest::SetIdentifier(int identifier)
{
	this->requestIdentifier = identifier;
}

int CRequest::GetIdentifier()
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

string CRequest::GetType_str()
{
	switch (this->operationType)
	{
	case MUL:
		return "MUL";
		break;
	case SUM:
		return "SUM";
		break;
	case SUB:
		return "SUB";
		break;
	case DIV:
		return "DIV";
		break;
	case NEG:
		return "NEG";
		break;
	default:
		return "NOVALIDTYPE";
		break;

	}
}

int CRequest::GetRequiredDiskPosition()
{
	switch (this->operationType)
	{
	case MUL:
		return 1;
		break;
	case SUM:
		return 3;
		break;
	case SUB:
		return 5;
		break;
	case DIV:
		return 4;
		break;
	case NEG:
		return 2;
		break;
	default:
		return -1;
		break;

	}
}

