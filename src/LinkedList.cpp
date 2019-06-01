#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		delete(first);
		first = temp;
	}
}

template <class T>
void LinkedList<T>::insertBack(T newData)
{
	Node<T>* newNode;
	newNode->data = newData;
	newNode->next = NULL;

	Node<T>* temp = first;

	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
	else
	{
		first = newNode;
	}
}

template <class T>
bool LinkedList<T>::removeBack()
{
	if (first == NULL && last == NULL) {return false;}

	if (first == last)
	{
		delete(first);
		last = NULL;
		first = last;
		return true;
	}

	else
	{
		Node<T>* temp = first;
		int nodeCount = 0;

		while (temp != NULL)
		{
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;

		for(int i = 1; i < (nodeCount - 1); i++)
		{
			temp2 = temp2->next;
		}
		delete(temp2->next);

		last = temp2;
		last->next = NULL;

		return true;
	}
}

template <class T>
void LinkedList<T>::insertFront(T newData)
{
	Node<T>* newNode;

	newNode->data = newData;

  	 if(first == NULL)
   	{
   		first = newNode;
   	}
   	else
   	{
   		newNode->next = first;
   		first = newNode;
   	}
}

template <class T>
bool LinkedList<T>::removeFront()
{
	if (first == NULL && last == NULL) {return false;}

	else
	{
		Node<T>* temp;

		temp = first;
		first = first->next;

		delete(temp);

		return true;
	}
}

template <class T>
void LinkedList<T>::clear()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		first = temp;
		delete(temp);
	}
}