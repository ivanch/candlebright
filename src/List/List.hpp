#pragma once
template <typename T>
class List {
    public:
        virtual void add(T _el) = 0;
        virtual void remove(T _el) = 0;
        //virtual void operator[](int _el) = 0;
};