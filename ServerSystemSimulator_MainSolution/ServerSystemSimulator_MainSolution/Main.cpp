#include <iostream>
#include "RequestQueue.h"
#include "ReadFile.h"
#include "Server.h"
#include "LoadBalancer.h"
#include <string>
#include "DisplayInformation.h"

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


	CLoadBalancer* loadBalancer = new CLoadBalancer(server1, server2, server3);


	//INICIA TICK
	int previousSuccesfullRequests = 0;
	int tick = 1;
	while (requestsQueue->Size() != 0)
	{
		cout << "---------------------- TICK  # " << tick << " ----------------------" << endl;
		//BalanceadorDeCarga Hace Deque a requestsQueue. Nota: BC asignara identifiers a las requests, no leer archivo.
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 1);
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 2);
		loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 3);

		// Diplay Requests For This Tick
		//CDisplayInformation* obj = new CDisplayInformation();


		cout << "Request cargadas al Balanceador de Carga:" << endl;
		//obj->DisplayRequestInformation(*(loadBalancer->GetCurrentFirstRequest()));
		CDisplayInformation::DisplayRequestInformation(loadBalancer->GetCurrentFirstRequest());
		CDisplayInformation::DisplayRequestInformation(loadBalancer->GetCurrentSecondRequest());
		CDisplayInformation::DisplayRequestInformation(loadBalancer->GetCurrentThirdRequest());





		//Comunicar con servidores


		if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentFirstRequest()) == false)
		{
			failedRequestsStack->Push(loadBalancer->GetCurrentFirstRequest());//If impossible, request to failed requests stack
			cout << "(La siguiente peticion no se asigno exitosamente):   ";
			CDisplayInformation::DisplayIdentifier(loadBalancer->GetCurrentFirstRequest());
		}

		if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentSecondRequest()) == false)
		{
			failedRequestsStack->Push(loadBalancer->GetCurrentSecondRequest());//If impossible, request to
			cout << "(La siguiente peticion no se asigno exitosamente):   ";
			CDisplayInformation::DisplayIdentifier(loadBalancer->GetCurrentSecondRequest());

		}

		if (loadBalancer->TryToAssignRequestToAServer(loadBalancer->GetCurrentThirdRequest()) == false)
		{
			failedRequestsStack->Push(loadBalancer->GetCurrentThirdRequest());//If impossible, request to
			cout << "(La siguiente peticion no se asigno exitosamente):   ";
			CDisplayInformation::DisplayIdentifier(loadBalancer->GetCurrentThirdRequest());

		}

		//Poner a trabajar a los servidores. Trabajaran lo que puedan trabajar por tick.
		//Los servidores envian automaticamente a la pila de requests exitosas un request cada vez que logran completar una
		previousSuccesfullRequests = succesfullRequestsStack->Size();
		server1->Work();
		server2->Work();
		server3->Work();

		// TERMINA TICK

		/*VariousFunctions.DisplaySuccesfullRequestsOnThisTick(succesfullRequestsStack.Size(), previousSuccesfullRequests);*/
		/*
		Adentro puede como if ( eso es diferente al otro)
		algoritmo para imprimir la cantidad necesaria
		sino
		no se completo alguna peticion en este tick...
		*/
		tick++;

	}
	CDisplayInformation::DisplayTotals(*succesfullRequestsStack, *failedRequestsStack);

	std::cin.get();
	return 0;
}