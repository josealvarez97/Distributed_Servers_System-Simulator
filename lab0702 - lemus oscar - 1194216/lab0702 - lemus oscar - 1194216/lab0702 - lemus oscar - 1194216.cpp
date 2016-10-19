// lab0702 - lemus oscar - 1194216.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "DoubleLinkedList.h"
#include "iostream"


int _tmain(int argc, _TCHAR* argv[])
{
	DoubleLinkedList *l = new DoubleLinkedList();
	
	l->Add(1);
	l->Add(3);
	l->Add(5);
	std::cout << (l->FirstElement()) << "\n";
	l->InsertFirst(8);
	std::cout << (l->FirstElement()) << "\n";
	l->Add(6);
	l->InsertBeforeOf(7, 3);
	l->InsertAfterOf(15, 3);
	std::cout << (l->LastElement()) << "\n";
	std::cout << (l->ItemAtIndex(3)) << "\n";
	std::cout << (l->IndexOf(15));
	l->RemoveHead();
	l->RemoveTail();
	l->RemoveNodeIn(3);
	std::cin.get();
	return 0;
}

