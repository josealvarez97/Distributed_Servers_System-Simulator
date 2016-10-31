#include "ReadFile.h"

CReadFile::CReadFile()
{
	

}


CReadFile::~CReadFile()
{
}


void CReadFile::ReadInput(string Entrada, int ServersProccessingInfo[3], int ServersRamInfo[3], int ServersOperationsPerTickInfo[3], CRequestQueue * requestQueue)
{
	file.open(Entrada, ios::in);
	string p = "";
	int serverCount = 0;
	int line = 0;
	int ID = 0;
	/*

	El asterisco * sirve para  --declarar un puntero-- Y para --"devolver la variable a la apunta"--.
	El amperson & sirve "devolver la direccion de memoria de una variable".

	*/
	//CRequest* aNewPointer; asterisco usado para declarar
	//CRequest aRequest;
	//aNewPointer = &aRequest;

	//CRequest* aRequestPointer = new CRequest();
	//(*aRequestPointer).GetIdentifier(); asterisco usado para devolver la variable a la que apuntaba el puntero


	while (!file.eof())
	{
		
		(getline(file, p));
		/* http://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c */ 
	
	
		// Read Servers Information / Especifications
		if (line < 3)
		{
			ServersProccessingInfo[serverCount] = atoi(p.substr(0, 2).c_str());
			ServersRamInfo[serverCount] = atoi(p.substr(3, 2).c_str());
			ServersOperationsPerTickInfo[serverCount] = atoi(p.substr(6, 2).c_str());
			serverCount++;

		}
		else if (p != "")
		{
			p.erase(remove_if(p.begin(), p.end(), isspace));

			CRequest *newRequest = new CRequest();
			//NEG, SUM, SUB, MUL, DIV
			if (p == "NEG")
			{
				newRequest->SetTypeOfOperation(NEG);
				// Next line: Read Proccessing Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetProcessingNumbers(p);
				// Next line: Read Ram Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetRamNumbers(p);
			}
			else if (p == "SUM")
			{
				newRequest->SetTypeOfOperation(SUM);
				// Next line: Read Proccessing Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetProcessingNumbers(p);
				// Next line: Read Ram Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetRamNumbers(p);
			}
			else if (p == "SUB") 
			{
				newRequest->SetTypeOfOperation(SUB);
				// Next line: Read Proccessing Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetProcessingNumbers(p);
				// Next line: Read Ram Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetRamNumbers(p);
			}
			else if (p == "MUL")
			{
				newRequest->SetTypeOfOperation(MUL);
				// Next line: Read Proccessing Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetProcessingNumbers(p);
				// Next line: Read Ram Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetRamNumbers(p);
			}
			else if (p == "DIV")
			{
				newRequest->SetTypeOfOperation(DIV);
				// Next line: Read Proccessing Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetProcessingNumbers(p);
				// Next line: Read Ram Numbers
				(getline(file, p));
				p.erase(remove_if(p.begin(), p.end(), isspace), p.end());
				newRequest->SetRamNumbers(p);
			}


			// Queue newRequest to RequestQueue
			newRequest->SetIdentifier(ID++);
			requestQueue->Queue(newRequest);
			//delete newRequest; no se elimina porque al no ser un puntero, automaticamente al salir de este metodo se llama al destructor de la clase
		}		
		line++;
	}
	file.close();
}
