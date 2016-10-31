#include "Server.h"




int CServer::RamFreeSpace()
{
	return this->serverRAM.GetMAX_SIZE() - this->serverRAM.Size();
}

int CServer::ProcessingQueueFreeSpace()
{
	return this->serverProcessingQueue.GetMAX_Size() - this->serverProcessingQueue.Size();
}

void CServer::OperateRam(int currentRequestRamNumbers, typeOfOperation type)
{
	//this->serverRequestsQueue.ReturnHead().
	int result = 0;
	int lastdigit;
	switch (type)
	{
	case NEG:
		result = this->serverRAM.RemoveHead() * -1;
		break;
	case SUM:
		while (currentRequestRamNumbers != 0)
		{
			result += this->serverRAM.RemoveHead();
			currentRequestRamNumbers--;
		}
		this->serverRequestsQueue->ReturnHead()->SetResult(result); // Al request actual le seteamos el resultado de su respectiva operación
		break;
	case SUB:
		while (currentRequestRamNumbers != 0)
		{
			result -= this->serverRAM.RemoveHead();
			currentRequestRamNumbers--;
		}
		this->serverRequestsQueue->ReturnHead()->SetResult(result);
		break;
	case MUL:
		/*
		Entrada: string ... 123456
		Algoritmo de lectura añade a ram leyendo string de izquierda a derecha
		/RAM HEAD/-----/ELEMENT 1/---....---/ELEMENT n - 1/---------/RAM TAIL/
		1              2                 5                       6


		*/


		while (currentRequestRamNumbers != 0)
		{
			result += this->serverRAM.FirstElement();
			currentRequestRamNumbers--;
			if (currentRequestRamNumbers == 1)
			{
				lastdigit = this->serverRAM.RemoveHead();
			}
		}
		result = result * lastdigit;
		this->serverRequestsQueue->ReturnHead()->SetResult(result);
		break;
	case DIV:

		while (currentRequestRamNumbers != 1)
		{
			result += this->serverRAM.RemoveHead();
			currentRequestRamNumbers--;
		}
		lastdigit = this->serverRAM.RemoveHead();
		result = result / lastdigit;
		this->serverRequestsQueue->ReturnHead()->SetResult(result);
		break;
	default:
		break;
	}
}

CServer::CServer(int processingSize, int ramSize, int operationsPerTick, CRequestStack * succesfullRequestsStack, CHardDisk* hardDisk, int ID)
{
	this->serverProcessingQueue.SetMAX_SIZE(processingSize);
	this->serverRAM.SetMAX_SIZE(ramSize);
	this->operationsPerTick = operationsPerTick;
	this->sucessfullRequestsStack = succesfullRequestsStack;

	// -1 means value out of context. we don't have a logical value to assign.
	this->CurrentRequestRAMNumbers = -1;
	this->CurrentRequestProcessingNumbersLeft = -1;

	this->serverRequestsQueue = new CRequestQueue();

	this->hardDisk = hardDisk;
	this->serverID = ID;
}

CServer::~CServer()
{
}

void CServer::Work()
{
	// Necesitamos algoritmos y formas de guardar la informacion de las peticioenes...
	int operations = 0;
	while (operations < this->operationsPerTick && this->serverRequestsQueue->Size() != 0)
	{

		// EVALUAR SI CONTADORES ESTAN FUERA DE CONTEXTO (Esto se daría cuando tengamos que trabajar un request "inicial" o que no tenga un request completado una operacion/instante antes)
		// Nota... el primer request en ejecutarse sera un problema para setear los contadores.
		if (this->CurrentRequestRAMNumbers == -1 && this->CurrentRequestProcessingNumbersLeft == -1)
		{
			// Reset ram numbers left. 
			this->CurrentRequestRAMNumbers = this->serverRequestsQueue->ReturnHead()->GetRamNumbers().length();
			// Reset processing numbers left.
			this->CurrentRequestProcessingNumbersLeft = this->serverRequestsQueue->ReturnHead()->GetProcessingNumbers().length();
		}


		// EVALUAR SI SE COMPLETO UN REQUEST UNA OPERACIÓN ANTES.
		if (this->serverRequestsQueue->ReturnHead()->IsComplete() == true)
		{
			// Push completed request to suceessful requests stack
			this->sucessfullRequestsStack->Push(serverRequestsQueue->Dequeue());

			if (this->serverRequestsQueue->Size() != 0) // EVALUAR SI REQUEST NO ESTA VACIA LUEGO DE HABER HECHO DEQUE (SIGNIFICA HAY REQUESTS ESPERANDO EN LA COLA...)
			{
				//(Next request quantity of ram numbers and processing numbers)
				// Reset ram numbers left. 
				this->CurrentRequestRAMNumbers = this->serverRequestsQueue->ReturnHead()->GetRamNumbers().length();
				// Reset processing numbers left.
				this->CurrentRequestProcessingNumbersLeft = this->serverRequestsQueue->ReturnHead()->GetProcessingNumbers().length();
			}
			else // SI ESTA VACIA ES PORQUE NO HABIAN REQUESTS ESPERANDO EN LA COLA. "APAGMOS EL MOTOR XD"
			{
				// Reset ram numbers left. 
				this->CurrentRequestRAMNumbers = -1;
				// Reset processing numbers left.
				this->CurrentRequestProcessingNumbersLeft = -1;
			}


		}
		else // TENEMOS UNA REQUEST EN PROCESO, EL CUAL HAY QUE CONTINUAR...
		{

			//EXECUTE  1 operation / o MOVEMOS EL DISCO DURO (1 o mas operaciones)

			// O SACAMOS UN ELEMENTO DE PROCESAMIENTO (1 operacion)
			if (this->CurrentRequestProcessingNumbersLeft != 0)
			{
				this->serverProcessingQueue.Dequeue();
				this->CurrentRequestProcessingNumbersLeft--;

				operations++; // AUMENTAMOS EL CONTADOR DE OPERACIONES

			}
			// O PREPARAMOS EL DISCO DURO (1 o más operaciones)
			else if (this->serverRequestsQueue->ReturnHead()->GetRequiredDiskPosition() != hardDisk->GetDiskPosition())
			{
				// RotateDisk(int targetPosition, int allowedOperations) returns the number of operations performed while rotating the disk. (it cannot rotate more times than whatthe server can in one tick).
				operations += this->hardDisk->RotateDisk(this->serverRequestsQueue->ReturnHead()->GetRequiredDiskPosition(), (this->operationsPerTick - operations));
			}
			// O OPERAMOS LA RAM (1 operaciones)
			else
			{
				// Operamos la ram... metodo void OperarRam(tipo de Operacion, etc)
				OperateRam(CurrentRequestRAMNumbers, this->serverRequestsQueue->ReturnHead()->GetTypeOfOperation());
				this->serverRequestsQueue->ReturnHead()->SetComplete(true);

				operations++; // AUMENTAMOS EL CONTADOR DE OPERACIONES
			}

		}




	}



}



bool CServer::AskAvailability(int processingSpaceNecessary, int ramSpaceNecessary)
{
	if (this->ProcessingQueueFreeSpace() >= processingSpaceNecessary
		&& this->RamFreeSpace() >= ramSpaceNecessary)
		return true;
	else
		return false;
}

void CServer::ReceiveRequest(CRequest *request)
{
	if (request != nullptr)
	{
		// Assign RAM numbers
		for (int i = 0; i < request->GetRamNumbers().length(); i++)
			this->serverRAM.Add(atoi(request->GetRamNumbers().substr(i, 1).c_str()));
		// Assign Processing numbers
		for (int i = 0; i < request->GetProcessingNumbers().length(); i++)
			this->serverProcessingQueue.Queue(atoi(request->GetProcessingNumbers().substr(i, 1).c_str()));

		// EnQueue request to Server Request Queue
		this->serverRequestsQueue->Queue(request);
	}





}

void CServer::PrintQueueState()
{
	CRequestQueue aCopy = *this->serverRequestsQueue;

	if (aCopy.Size() > 0)
		for (int i = aCopy.Size(); i > 0; i--)
		{
			cout << " * [" << "ID:" << aCopy.ReturnHead()->GetIdentifier() << " (" << aCopy.ReturnHead()->GetType_str().c_str() << ") ]" << endl;
			aCopy.Dequeue();
		}
	else
		cout << "El servidor no tiene peticiones asignadas" << endl;


}

void CServer::PrintServerInfo()
{
	cout << "(Espacio Libre Ram:" << RamFreeSpace() << " - Procesamiento:" << ProcessingQueueFreeSpace() << ")" << endl;
}

bool CServer::IsWorking()
{
	if (this->serverRequestsQueue->Size() > 0)
		return true;
	else
		return false;
}

int CServer::GetServerRank()
{

		int degreeServer;

		if (this->serverRequestsQueue->Size() != 0)
			degreeServer = this->serverRequestsQueue->Size();
		else
			degreeServer = 0;

		CRequestQueue aCopyOfServerRequestsQueue = *this->serverRequestsQueue;
		int weightOfRequests = 0;
		for (int i = aCopyOfServerRequestsQueue.Size(); i > 0; i--)
		{
			weightOfRequests += aCopyOfServerRequestsQueue.ReturnHead()->GetProcessingNumbers().length() + aCopyOfServerRequestsQueue.ReturnHead()->GetRamNumbers().length();
			aCopyOfServerRequestsQueue.Dequeue();
		}

		int serverRank = (degreeServer * weightOfRequests) / operationsPerTick;
		return serverRank;

	
}
