#pragma once
#include <iostream>
#include "includes.hpp"

template <class T>
class LinkedList
{
    public:
		template <class TE>
		class Node
		{
			private:
				TE* data;
				Node<TE>* next;

			public:

				TE* getData(){return data;}
				void setData(TE* _data){data=_data;}

				Node<TE>* getNext(){return next;}
				void setNext(Node<TE>* next){this->next=next;}
		};

        LinkedList();
        ~LinkedList();
        void insertBack(T *newData);
        bool removeBack();

        void insertFront(T *newData);
        bool removeFront();
        void removeNth(T *data);

        void clear();

        Node<T>* operator [] (int chave);


        Node<T>* getFirst(){return first;}
        Node<T>* getLast(){return last;}

    private:
        Node<T> *first;
        Node<T> *last;
};

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
		temp = temp->getNext();
		delete(first);
		first = temp;
	}
}

template <class T>
void LinkedList<T>::insertBack(T* newData)
{
	Node<T>* newNode = new Node<T>;
	newNode->setData(newData);
	newNode->setNext(NULL);

	if(first == NULL) first = newNode;

    if(last != NULL)
    {
        last->setNext(newNode);
        last = newNode;
    }
    else
        last = newNode;
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
void LinkedList<T>::insertFront(T *newData)
{
	Node<T>* newNode = new Node<T>;

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
void LinkedList<T>::removeNth(T *data){

    if(first == NULL)
        return;

    Node<T>* temp = first;

    if(temp == data)
    {
        first = temp->next;
        free(temp);
        return;
    }

     while (temp->next!=data)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
        return;


    next = temp->next->next;
    free(temp);
    temp->next = next;

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

template <class T>
LinkedList<T>::Node<T>* LinkedList<T>::operator[](int chave)
{
    Node<T>* temp = first;
    for (int i=0; i<chave; i++)
        temp = temp->getNext();

    return temp;
}
