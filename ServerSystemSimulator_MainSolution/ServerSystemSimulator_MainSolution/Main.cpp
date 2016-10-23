#include <iostream>
#include "RequestQueue.h"
#include "ReadFile.h"
#include <string>

using namespace std;

int main()
{



	int ServersProcessingInfo[3];
	int ServersRamInfo[3];
	int ServersOperationsPerTickInfo[3];

	//int* ServersProcessingInfoPtr = ServersProcessingInfo;
	//int* ServersRamInfoPtr = ServersRamInfo;
	//int* ServersOperationsPerTickInfoPtr = ServersOperationsPerTickInfo;
	CRequestQueue* requestsQueue = new CRequestQueue(); //Tendra en su metodo addRequest(string info, string info..que leeremos en LeerArchivoDeTexto)
	//RequestStack* failedRequestsStack = new RequestsStack();
	//RequestStack* succesfullRequestsStack = new RequestsStack();

	

	//Leer entrada y Meter Requests en CR
	CReadFile* objReadFile = new CReadFile();
	objReadFile->ReadInput("C:/Users/Oscar/Desktop/Proyecto Servidores/ServerSystemSimulator_MainSolution/ServerSystemSimulator_MainSolution/Entrada.txt", ServersProcessingInfo, ServersRamInfo, ServersOperationsPerTickInfo, requestsQueue);
	

	cout << "HOLI" << endl;
	cout << ServersProcessingInfo[1] << endl;
	cout << requestsQueue->Dequeue()->GetTypeOfOperation() << endl;
	
	
	
	
	
	
	
	
	
	
	
	

	cin.get();
	return 0;
}