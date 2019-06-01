#pragma once
#include <iostream>
#include "includes.hpp"

template <class T>
class Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertBack(T newData);
        bool removeBack();

        void insertFront(T newData);
        bool removeFront();

        void clear();

    private:
        Node<T> *first;
        Node<T> *last;
};