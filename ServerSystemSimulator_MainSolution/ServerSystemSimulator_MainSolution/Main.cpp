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
	try
	{
		// Variables Used For Taking Input
		int ServersProcessingInfo[3];
		int ServersRamInfo[3];
		int ServersOperationsPerTickInfo[3];
		string Entrada;

		// DECLARATION OF QUEUES AND STACKS
		CRequestQueue* requestsQueue = new CRequestQueue();
		CRequestStack* failedRequestsStack = new CRequestStack();
		CRequestStack* succesfullRequestsStack = new CRequestStack();

		cout << "-------------------------------ESCRIBA LA DIRECCION DEL ARCHIVO PARA REALIZAR LA SIMULACION--------------------------------" << endl;
		getline(cin, Entrada);
		cout << endl << endl << endl;

		//READ INPUT and queue requests/input into requests queue
		CReadFile* objReadFile = new CReadFile();
		objReadFile->ReadInput(Entrada, ServersProcessingInfo, ServersRamInfo, ServersOperationsPerTickInfo, requestsQueue);


		//INITIALIZE OBJECTS
		CHardDisk* hardDisk = new CHardDisk();

		CServer* server1 = new CServer(ServersProcessingInfo[0], ServersRamInfo[0], ServersOperationsPerTickInfo[0], succesfullRequestsStack, hardDisk, 1);
		CServer* server2 = new CServer(ServersProcessingInfo[1], ServersRamInfo[1], ServersOperationsPerTickInfo[1], succesfullRequestsStack, hardDisk, 2);
		CServer* server3 = new CServer(ServersProcessingInfo[2], ServersRamInfo[2], ServersOperationsPerTickInfo[2], succesfullRequestsStack, hardDisk, 3);

		CLoadBalancer* loadBalancer = new CLoadBalancer(server1, server2, server3);


		// START TICK
		int previousSuccesfullRequests = 0; // variable used as a reference to know how many requests are succesfully completed per tick
		int tick = 1;
		while (requestsQueue->Size() != 0
			|| server1->IsWorking() == true || server2->IsWorking() == true || server3->IsWorking() == true)
		{
			cout << "------------------------------------------------------- TICK  # " << tick << " ------------------------------------------------------- " << endl;


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



			//LOAD BALANCER TAKES THREE REQUESTS FROM REQUESTS QUEUE
			loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 1);
			loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 2);
			loadBalancer->TakeRequestFromRequestQueue(requestsQueue->Dequeue(), 3);

			// PRINT REQUESTS LOAD ON LOAD BALANCER
			cout << "## PETICIONES CARGADAS AL BALANCEADOR DE CARGA ##:" << endl;
			if (loadBalancer->GetCurrentFirstRequest() != nullptr)
				CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentFirstRequest());
			if (loadBalancer->GetCurrentSecondRequest() != nullptr)
				CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentSecondRequest());
			if (loadBalancer->GetCurrentThirdRequest() != nullptr)
				CDisplayInformation::DisplayRequestInformation(*loadBalancer->GetCurrentThirdRequest());
			cout << endl;





			// COMUNICATION OF LOAD BALANCER WITH SERVERS
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


			// --------------------------MAKE THE SERVERS WORK.------------------------------
			//Poner a trabajar a los servidores. Trabajaran lo que puedan trabajar por tick.
			//Los servidores envian automaticamente a la pila de requests exitosas un request cada vez que logran completar una
			previousSuccesfullRequests = succesfullRequestsStack->Size();
			server1->Work();
			server2->Work();
			server3->Work();

			// TICK ENDS

			CDisplayInformation::DisplaySuccesfullRequestsOnThisTick(*succesfullRequestsStack, previousSuccesfullRequests);
			tick++;

		}




		// PRINT LAST SYSTEM STATES. JUST TO MAKE CLEAR TO THE USER THAT EVERYTHING WAS PERFORMED CORRECTLY.
		cout << "------------------------------------------------------ FIN DE SIMULACION ------------------------------------------------------" << endl;
		cout << "## ESTADO DEL SISTEMA AL HABER FINALIZADO LOS TICKS ##" << endl;
		cout << "--SERVIDOR 1: "; server1->PrintServerInfo();
		server1->PrintQueueState();
		cout << "--SERVIDOR 2: "; server2->PrintServerInfo();
		server2->PrintQueueState();
		cout << "--SERVIDOR 3: "; server3->PrintServerInfo();
		server3->PrintQueueState();
		cout << "--POSICION DISCO DURO: " << hardDisk->GetDiskPosition() << endl;
		cout << endl << endl << endl;

		CDisplayInformation::DisplayTotals(*succesfullRequestsStack, *failedRequestsStack);


		cout << "\n POST DATA: No se sorprenda si hay demasiadas peticiones exitosas, aseguramos que nuestro programa \n asigna cada peticion al servidor en mejores condiciones. Consulte Readme para conocer los detalles de dicha optimizacion." << endl;

		std::cin.get();

	}
	catch (exception e)
	{
		cout << "Algo salio mal. Cierre el programa e intente nuevamente. " << endl 
			<< "(Probablemente ingreso mal la entrada, consulte ejemplo en ReadMe.md y verifique que escribio correctamente la direccion del archivo.)" << endl;
		cin.get();
	}

	return 0;

}