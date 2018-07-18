#pragma once

template <class T>
struct element
{
    element() : next(0), prev(0) {};
    element(T val) : next(0), prev(0), value(val) {};
    element(T val, element *prev_elem) : value(val), prev(prev_elem), next(0) {};
    element(T val, element *prev_elem, element *next_elem) : value(val), prev(prev_elem), next(next_elem) {};
    T value;
    element<T> *next;
    element<T> *prev;
};

template <class T>
class List
{
    public:
        // List();
        // ~List();
        List<T> &Add(T elem);
        List<T> &Insert(T elem, int pos);
        int Length();
        int Search(T elem);
        void Remove(int pos);
        int &operator[](int pos);
        element<T>* GetRoot();
        int GetSize(); 
    private:
        element<T> *root;
        int size_ = 0;
};