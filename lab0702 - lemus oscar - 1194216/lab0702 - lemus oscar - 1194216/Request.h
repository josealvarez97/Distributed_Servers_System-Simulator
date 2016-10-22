#pragma once
#include <iostream>
enum typeOfOperation {NEG, SUM, SUB, MUL, DIV}; //NEG = 0, SUM = 1...
using namespace std;
class CRequest
{
private:
	typeOfOperation operationType;
	string processingQueueNumbers;
	string ramNumbers;
	char requestIdentifier;
public:
	CRequest();
	~CRequest();
	void SetTypeOfOperation(typeOfOperation Type);
	void SetProcessingNumbers(string numbers);
	void SetRamNumbers(string numbers);
	int GetTypeOfOperation();
	string GetProcessingNumbers();
	string GetRamNumbers();
	void SetIdentifier(char identifier);
	char GetIdentifier();
};

