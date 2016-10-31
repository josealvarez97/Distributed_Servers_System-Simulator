#include <iostream>
#include "RequestQueue.h"
#include "ReadFile.h"
#include "Server.h"
#include "LoadBalancer.h"
#include <string>
#include "DisplayInformation.h"
#include "HardDisk.h"

using namespace std;

int main()
{



	int ServersProcessingInfo[3];
	int ServersRamInfo[3];
	int ServersOperationsPerTickInfo[3];
	string Entrada;


	CRequestQueue* requestsQueue = new CRequestQueue(); //Tendra en su metodo addRequest(string info, string info..que leeremos en LeerArchivoDeTexto)
														// NO TIENEN METODOS LAS SIGUIENTES DOS, SOLO ESTAN DECLARADAS. OSCAR TE TOCA :(
	CRequestStack* failedRequestsStack = new CRequestStack();
	CRequestStack* succesfullRequestsStack = new CRequestStack();

	cout << "-------------------------------ESCRIBA LA DIRECCION DEL ARCHIVO PARA REALIZAR LA SIMULACION--------------------------------" << endl;
	getline(cin, Entrada);
	cout << endl << endl << endl;

	//Leer entrada y Meter Requests en CR
	CReadFile* objReadFile = new CReadFile();
	objReadFile->ReadInput(Entrada, ServersProcessingInfo, ServersRamInfo, ServersOperationsPerTickInfo, requestsQueue);


	//Inicializar Objetos
	CHardDisk* hardDisk = new CHardDisk();

	CServer* server1 = new CServer(ServersProcessingInfo[0], ServersRamInfo[0], ServersOperationsPerTickInfo[0], succesfullRequestsStack, hardDisk);
	CServer* server2 = new CServer(ServersProcessingInfo[1], ServersRamInfo[1], ServersOperationsPerTickInfo[1], succesfullRequestsStack, hardDisk);
	CServer* server3 = new CServer(ServersProcessingInfo[2], ServersRamInfo[2], ServersOperationsPerTickInfo[2], succesfullRequestsStack, hardDisk);


	CLoadBalancer* loadBalancer = new CLoadBalancer(server1, server2, server3);


	//INICIA TICK
	int previousSuccesfullRequests = 0;
	int tick = 1;
	while (requestsQueue->Size() != 0 
		|| server1->IsWorking() == true || server2->IsWorking() == true || server3->IsWorking() == true)
	{
		cout << "------------------------------------------------------- TICK  # " << tick << " ------------------------------------------------------- "<< endl;


		// PRINT SYSTEM STATE BEFORE TICK
		cout << "## ESTADO DEL SISTEMA ANTES DEL TICK ##" << endl;
		cout << "--SERVIDOR 1: "; server1->PrintServerInfo();
		server1->PrintQueueState();
		cout << "--SERVIDOR 2: "; server2->PrintServerInfo();
		server2->PrintQueueState();
		cout << "--SERVIDOR 3: "; server3->PrintServerInfo();
		server3->PrintQueueState();
		cout << "--POSICION DISCO DURO: " << hardDisk->GetDiskPosition() << endl;
		cout << endl;



		//BalanceadorDeCarga Hace Deque a requestsQueue. Nota: BC asignara identifiers a las requests, no leer archivo.
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 1);
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 2);
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 3);

		// Diplay Requests For This Tick
		//CDisplayInformation* obj = new CDisplayInformation();


		cout << "## PETICIONES CARGADAS AL BALANCEADOR DE CARGA ##:" << endl;
		//obj->DisplayRequestInformation(*(loadBalancer->GetCurrentFirstRequest()));
		if (loadBalancer->GetCurrentFirstRequest() != nullptr)
			CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentFirstRequest());
		if (loadBalancer->GetCurrentSecondRequest() != nullptr)
			CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentSecondRequest());
		if (loadBalancer->GetCurrentThirdRequest() != nullptr)
			CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentThirdRequest());
		cout << endl;





		//Comunicar con servidores
		cout << "## ASIGNACION DE PETICIONES A LOS SERVIDORES ##" << endl;
		if (loadBalancer->GetCurrentFirstRequest() != nullptr)
			if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentFirstRequest()) == false)
			{
				failedRequestsStack->Push(loadBalancer->GetCurrentFirstRequest());//If impossible, request to failed requests stack
				cout << "(La siguiente peticion NO se asigno exitosamente):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentFirstRequest());
			}
			else
			{
				cout << "(La siguiente se asigno sin problemas al servidor #" << loadBalancer->GetlastServerAssignation() << "):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentFirstRequest());
			}
		if (loadBalancer->GetCurrentSecondRequest() != nullptr)
			if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentSecondRequest()) == false)
			{
				failedRequestsStack->Push(loadBalancer->GetCurrentSecondRequest());//If impossible, request to
				cout << "(La siguiente peticion no se asigno exitosamente):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentSecondRequest());
			}
			else
			{
				cout << "(La siguiente se asigno sin problemas al servidor #" << loadBalancer->GetlastServerAssignation() << "):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentSecondRequest());
			}
		if (loadBalancer->GetCurrentThirdRequest() != nullptr)
			if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentThirdRequest()) == false)
			{
				failedRequestsStack->Push(loadBalancer->GetCurrentThirdRequest());//If impossible, request to
				cout << "(La siguiente peticion no se asigno exitosamente):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentThirdRequest());
			}
			else
			{
				cout << "(La siguiente se asigno sin problemas al servidor #" << loadBalancer->GetlastServerAssignation() << "):   ";
				CDisplayInformation::DisplayIdentifier(*loadBalancer->GetCurrentThirdRequest());
			}
		cout << endl;

		//Poner a trabajar a los servidores. Trabajaran lo que puedan trabajar por tick.
		//Los servidores envian automaticamente a la pila de requests exitosas un request cada vez que logran completar una
		previousSuccesfullRequests = succesfullRequestsStack->Size();
		server1->Work();
		server2->Work();
		server3->Work();

		// TERMINA TICK

		CDisplayInformation::DisplaySuccesfullRequestsOnThisTick(*succesfullRequestsStack, previousSuccesfullRequests);
		/*
		Adentro puede como if ( eso es diferente al otro)
		algoritmo para imprimir la cantidad necesaria
		sino
		no se completo alguna peticion en este tick...
		*/
		tick++;

	}

	cout << "------------------------------------------------------" << endl;
	cout << "## ESTADO DEL SISTEMA AL HABER FINALIZADO LOS TICKS  (se suponia que terminaban cuando todo quedaba vacio :v) ##" << endl;
	cout << "--SERVIDOR 1: "; server1->PrintServerInfo();
	server1->PrintQueueState();
	cout << "--SERVIDOR 2: "; server2->PrintServerInfo();
	server2->PrintQueueState();
	cout << "--SERVIDOR 3: "; server3->PrintServerInfo();
	server3->PrintQueueState();
	cout << "--POSICION DISCO DURO: " << hardDisk->GetDiskPosition() << endl;
	cout << endl << endl << endl;

	CDisplayInformation::DisplayTotals(*succesfullRequestsStack, *failedRequestsStack);

	std::cin.get();
	return 0;
}