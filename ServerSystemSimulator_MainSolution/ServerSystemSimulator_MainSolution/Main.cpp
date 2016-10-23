#include <iostream>
#include "RequestQueue.h"
#include "ReadFile.h"
#include "Server.h"
#include <string>

using namespace std;

int main()
{



	int ServersProcessingInfo[3];
	int ServersRamInfo[3];
	int ServersOperationsPerTickInfo[3];

	CRequestQueue* requestsQueue = new CRequestQueue(); //Tendra en su metodo addRequest(string info, string info..que leeremos en LeerArchivoDeTexto)
	// NO TIENEN METODOS LAS SIGUIENTES DOS, SOLO ESTAN DECLARADAS. OSCAR TE TOCA :(
	CRequestStack* failedRequestsStack = new CRequestStack();
	CRequestStack* succesfullRequestsStack = new CRequestStack();

	

	//Leer entrada y Meter Requests en CR
	CReadFile* objReadFile = new CReadFile();
	objReadFile->ReadInput("C:/Users/Oscar/Desktop/Proyecto Servidores/ServerSystemSimulator_MainSolution/ServerSystemSimulator_MainSolution/Entrada.txt", ServersProcessingInfo, ServersRamInfo, ServersOperationsPerTickInfo, requestsQueue);
	

	//Inicializar Objetos
	CServer* server1 = new CServer(ServersProcessingInfo[1], ServersRamInfo[1], ServersOperationsPerTickInfo[1], succesfullRequestsStack);
	CServer* server2 = new CServer(ServersProcessingInfo[2], ServersRamInfo[2], ServersOperationsPerTickInfo[2], succesfullRequestsStack);
	CServer* server3 = new CServer(ServersProcessingInfo[3], ServersRamInfo[3], ServersOperationsPerTickInfo[3], succesfullRequestsStack);

	cout << "HOLI" << endl;
	cout << ServersProcessingInfo[1] << endl;
	cout << requestsQueue->Dequeue()->GetTypeOfOperation() << endl;
	
	
	
	
	
	
	
	
	
	
	
	

	cin.get();
	return 0;
}