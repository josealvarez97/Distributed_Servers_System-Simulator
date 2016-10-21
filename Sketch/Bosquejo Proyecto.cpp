//Asumimos que Ya instanciamos todo

int main()
{
	int[]* ServersProcessingInfo = new int[3];
	int[]* ServersRamInfo = new int[3];
	int[]* ServersOperationsPerTickInfo = new int[3];
	RequestQueue* requestsQueue = new RequestQueue(); //Tendra en su metodo addRequest(string info, string info..que leeremos en LeerArchivoDeTexto)
	RequestStack* failedRequestsStack = new RequestsStack();
	RequestStack* succesfullRequestsStack = new RequestsStack();






	//Leer entrada y Meter Requests en CR
	VariousFunctions.ReadTextFile(ServersProccessingInfo, ServersRamInfo, ServersOperationsPerTickInfo, requestsQueue);
	//Inicializar Objetos
	Server* server1 = new Server(ServersProcessingInfo[1], ServersRamInfo[1], ServersOperationsPerTickInfo[1], succesfullRequestsStack);
	Server* server2 = new Server(ServersProcessingInfo[2], ServersRamInfo[2], ServersOperationsPerTickInfo[2], succesfullRequestsStack);
	Server* server3 = new Server(ServersProcessingInfo[3], ServersRamInfo[3], ServersOperationsPerTickInfo[3], succesfullRequestsStack);

	LoadBalancer* loadBalancer = new LoadBalancer(server1, server2, server3);

	//INICIA TICK
	int previousSuccesfullRequests = 0;
	While(requestsQueue.Size() != 0)
	{
		//BalanceadorDeCarga Hace Deque a requestsQueue. Nota: BC asignara identifiers a las requests, no leer archivo.
		loadBalancer.TakeRequestFromRequestQueue(requestQueue.Dequeue());
		loadBalancer.TakeRequestFromRequestQueue(requestQueue.Dequeue());
		loadBalancer.TakeRequestFromRequestQueue(requestQueue.Dequeue());

		// Diplay Requests For This Tick
		cout << "Request cargadas al Balanceador de Carga:" << endl;
		VariousFunctions.DisplayInformationOfRequest(loadBalancer.CurrentFirstRequest());
		VariousFunctions.DisplayInformationOfRequest(loadBalancer.CurrentSecondRequest());
		VariousFunctions.DisplayInformationOFRequest(loadBalancer.CurrentThirdRequest());

		//Comunicar con servidores

		/*
		Lo siguiente ira dentro de loadBalancer.TryToAssignRequestToAServer()
		server1.AskAvailability(aRequest);
		server2.AskAvailability(aRequest);
		server3.AskAvailability(aRequest);
		*/
		if(loadBalancer.TryToAssignRequestToAServer() == false)
		{
			failedRequestsStack.Push(loadBalancer.CurrentFirstRequest())//If impossible, request to failed requests stack
			cout << "(La siguiente peticion no se asigno exitosamente)" << endl;
			VariosFunctions.DisplayInformationOfRequest(loadBalancer.CurrentFirstRequest());
		}

		if(loadBalancer.TryToAssignRequestToAServer() == false)
		{
			failedRequestsStack.Push(loadBalancer.CurrentSecondRequest())//If impossible, request to
			cout << "(La siguiente peticion no se asigno exitosamente)" << endl;
			VariosFunctions.DisplayInformationOfRequest(loadBalancer.CurrentFirstRequest());

		}

		if(loadBalancer.TryToAssignRequestToAServer() == false)
		{
			failedRequestsStack.Push(loadBalancer.CurrentThirdRequest())//If impossible, request to
		    cout << "(La siguiente peticion no se asigno exitosamente)" << endl;
			VariosFunctions.DisplayInformationOfRequest(loadBalancer.CurrentFirstRequest());

		}


		//Poner a trabajar a los servidores. Trabajaran lo que puedan trabajar por tick.
		//Los servidores envian automaticamente a la pila de requests exitosas un request cada vez que logran completar una
		previousSuccesfullRequests = successfullRequestsStack.Size();
		server1.Work();
		server2.Work();
		server3.Work();

		// TERMINA TICK

		VariousFunctions.DisplaySuccesfullRequestsOnThisTick(succesfullRequestsStack.Size(), previousSuccesfullRequests);
		/*
				Adentro puede como if ( eso es diferente al otro)
				algoritmo para imprimir la cantidad necesaria
				sino
				no se completo alguna peticion en este tick...
		*/

	}

	VariousFunctions.DisplayTotals(succesfullRequestsStack, failedRequestsStack);

	cout << "Gracias" << endl;


}
