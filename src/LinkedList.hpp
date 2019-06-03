#pragma once
#include <iostream>
#include "includes.hpp"

template <class T>
class Node
{
    private:
        T* data;
        Node<T>* next;

    public:

        T* getData(){return data;}
        void setData(T* data){this->data=data;}

        Node<T>* getNext(){return next;}
        void setNext(Node<T>* next){this->next=next;}
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertBack(T *newData);
        bool removeBack();

        void insertFront(T *newData);
        bool removeFront();

        void clear();

        Node<T>* operator [] (int chave);



        Node<T>* getFirst(){return first;}
        void setFirst(Node<T>* first){this->first=first;}


        Node<T>* getLast(){return last;}
        void setLast(Node<T>* last){this->last=last;}

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
	Node<T>* newNode;
	newNode->setData(newData);
	newNode->setNext(NULL);

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

template <class T>
Node<T>* LinkedList<T>::operator [] (int chave)
{
    Node<T>* temp = first;
    for (int i=0; i<chave; i++)
        temp = temp->getNext();

    return temp;
}
