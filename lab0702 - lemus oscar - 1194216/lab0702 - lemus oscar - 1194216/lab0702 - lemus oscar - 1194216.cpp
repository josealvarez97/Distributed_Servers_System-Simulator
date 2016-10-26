// lab0702 - lemus oscar - 1194216.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "DoubleLinkedList.h"
#include "iostream"
#include "Request.h"
#include "ReadFile.h"

int _tmain(int argc, _TCHAR* argv[])
{
	DoubleLinkedList *l = new DoubleLinkedList();
	ReadFile * n = new ReadFile();
	n->ReadInput("..\\..\\..\\..\\..\\..\\Entrada.txt");

	std::cin.get();

	CRequest* aRequest = new CRequest();
	aRequest->SetTypeOfOperation(MUL);
	aRequest->SetRamNumbers("1456854");
	aRequest->SetProcessingNumbers("1242452");
	int a = 0;
	aRequest->SetIdentifier(a);
	// o con char
	char b = 1;
	aRequest->SetIdentifier(b);

	return 0;
}

