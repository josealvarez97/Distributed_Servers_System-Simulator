#include "stdafx.h"
#include "DoubleLinkedList.h"
#include <yvals.h>


DoubleLinkedList::DoubleLinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	counter = 0; // let's use complete names for variables for easier understanding between each other... (counter) att. Jose
}


DoubleLinkedList::~DoubleLinkedList()
{

	while (this->head)
	{
		// pasar al siguiente
		this->head = this->head->getNext();


		// El anterior tiene algo diferente de null
		if (this->head->getPrevious())
		{
			delete this->head->getPrevious();
		}
	}
	delete this->tail;
}


bool DoubleLinkedList::Add(int number)
{
	if (this->head)
	{
		DNode  *n = new DNode(number);
		n->setPrevious(this->tail);
		this->tail->setNext(n); 
		this->tail = n;
		counter++;
		//agregar al final

	}
	else
	{
		DNode  *n = new DNode(number);
		this->head = n;
		this->tail = n;
		counter++;
		//agregar al inicio
	}
	return false;
}

/// Insert at the beggining of the list
bool DoubleLinkedList::InsertFirst(int number)
{
	if (this->head)
	{
		DNode * n = new DNode(number);
		this->head->setPrevious(n);
		n->setNext(this->head);
		this->head = n;
		counter++;
	}
	else
	{
		DNode *n = new DNode(number);
		this->head = n;
		this->tail = n;
		counter++;
	}
	return false;
}

/// This method returns the value of the first element in the list.
int DoubleLinkedList::FirstElement()
{
	if (counter > 0)
	{
		return this->head->getValue();
	}
	return -1;
	
}

/// This method returns the size of the list
int DoubleLinkedList::Size()
{
	return counter;
}

//Returns the value of the last element of the list
int DoubleLinkedList::LastElement()
{
	if (counter > 0)
	{
		return this->tail->getValue();
	}
	return -1;
}





// This method removes the first element of the list
bool DoubleLinkedList::RemoveHead()
{
	if (counter > 0)
	{
		DNode * Temp = new DNode();
		Temp = this->head;

		this->head = Temp->getNext();
		this->head->setPrevious(nullptr);
		counter--;
		return true;
	}
	return false;
}




// This method returns the node in a specific position
int DoubleLinkedList::ItemAtIndex(int index)
{
	int position = 0;
	DNode *Temp = new DNode();
	Temp = this->head;

	while (position != index)
	{
		Temp = Temp->getNext();
		position++;
	}
	return Temp->getValue();
}




bool DoubleLinkedList::InsertBeforeOf(int number, int position)
{
	if (counter >  0)
	{
		int temporary = 0;
		DNode *Temp1 = new DNode();
		DNode *Temp = new DNode(number);

		Temp1 = this->head;

		while (temporary < position)
		{
			Temp1 = Temp1->getNext();
			temporary++;
		}

		
		Temp->setPrevious(Temp1->getPrevious()); // Setea el previous del nuevo nodo a lo que apuntara el previous del nodo temporal1
		Temp1->getPrevious()->setNext(Temp); // Al previous del nodo temporal1 le setea de next el nuevo nodo.
		Temp->setNext(Temp1); // Al nodo que se desea agregar se le setea de next el temporal1
		Temp1->setPrevious(Temp); // Setea el previous del nodo temporal1 al nodo que se desea agregar.
		counter++;
	}
	return false;
}


bool DoubleLinkedList::InsertAfterOf(int number, int position)
{
	if (counter > 0)
	{
		int temporary = 0;
		DNode * Temp1 = new DNode();
		DNode * Temp = new DNode(number);
		
		Temp1 = this->head;

		while (temporary < position)
		{
			Temp1 = Temp1->getNext();
			temporary++;
		}

		Temp->setPrevious(Temp1); // Setea el previous del nuevo nodo al temporal1, que sera la posicion recibida por parametro
		Temp->setNext(Temp1->getNext()); // Setea el next del nuevo nodo a lo que sea que apuntara el next del temporal1
		Temp1->getNext()->setPrevious(Temp); // Setea el previous del nodo siguiente a temporal1 a el nuevo nodo
		Temp1->setNext(Temp); //Setea el next del nodo temporal1 al nuevo nodo
		counter++;
	}
	return false;
}



// Returns the position of a specific value in the list
int DoubleLinkedList::IndexOf(int value)
{
	if (counter > 0)
	{
		int temporary = 0;
		DNode * Temp = new DNode();

		Temp = this->head;

		while (value != Temp->getValue())
		{
			Temp = Temp->getNext();
			temporary++;
		}
		return temporary;
	}
	return 0;
}


bool DoubleLinkedList::RemoveTail()
{
	if (counter > 0)
	{
		DNode * Temp = new DNode();
		Temp = this->tail;

		this -> tail = Temp->getPrevious();
		this->tail->setNext(nullptr);
		counter--;
	}
	return false;
}


bool DoubleLinkedList::RemoveNodeIn(int position)
{
	if (counter > 0)
	{
		int temporary = 0;
		DNode * Temp1 = new DNode();
		Temp1 = this->head;

		while (temporary != position)
		{
			Temp1 = Temp1->getNext();
			temporary++;
		}

		Temp1->getPrevious()->setNext(Temp1->getNext()); // Al previous (nodo anterior) del temporal1 le setea de next el next del temporal1
		Temp1->getNext()->setPrevious(Temp1->getPrevious()); // Al next (nodo siguiente) del temporal1 se le asigna de previous el previous del temporal1
		counter--;
	}
	return false;
}
