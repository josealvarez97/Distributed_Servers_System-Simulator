#include "stdafx.h"
#include "ReadFile.h"


ReadFile::ReadFile()
{
	

}


ReadFile::~ReadFile()
{
}


void ReadFile::ReadInput(string Entrada)
{
	file.open(Entrada);
	string p = "";
	


	while (!file.eof())
	{
		
		(getline(file, p));
		cout << p << "\n";
		
	}
	file.close();
}
