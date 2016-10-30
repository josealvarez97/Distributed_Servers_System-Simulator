#pragma once
#include <iostream>
enum typeOfOperation {NEG, SUM, SUB, MUL, DIV, NOTYPE}; //NEG = 0, SUM = 1...
using namespace std;
class CRequest
{
private:
	typeOfOperation operationType;
	string processingQueueNumbers;
	int numberOfProcessingSpacesNeeded;
	string ramNumbers;
	int numberOfRamSpacesNeeded;
	int requestIdentifier;
	bool completed;
	int result;
public:
	CRequest();
	~CRequest();
	void SetTypeOfOperation(typeOfOperation Type);
	void SetProcessingNumbers(string numbers);
	void SetRamNumbers(string numbers);
	typeOfOperation GetTypeOfOperation();
	string GetProcessingNumbers();
	string GetRamNumbers();
	void SetIdentifier(int identifier);
	int GetIdentifier();
	bool IsComplete();
	int GetResult();
	void SetResult(int number);
	void SetComplete(bool value);
	string GetType_str();
};

