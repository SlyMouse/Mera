#include "../Headers/List.h"
#include <iostream>

template <class T>
int &List<T>::operator[](int pos)
{
    if(pos >= size_ || pos < 0)
        exit(2);

    element<T> *curr_elem = root;
    for(int i = 0; i < pos; i++)
        curr_elem = curr_elem->next;
    int &value = curr_elem->value;

    return value;
}

template <class T>
List<T> &List<T>::Add(T elem)
{
    if(!size_)
    {
        size_ = 1;
        root = new element<T>(elem);
    }
    else
    {
        element<T> *last_elem = root;
        for(int i = 0; i < size_ - 1; i++)
            last_elem = last_elem->next;
        element<T> *new_elem = new element<T>(elem, last_elem);
        last_elem->next = new_elem;
        size_++;
    }

    return *this;
}

template <class T>
List<T> &List<T>::Insert(T elem, int pos)
{
    /* if(pos >= size_ && pos < 0)
        exit(2);

    (*this)[pos] = elem;
    return *this; */
    
    if(!pos)
    {
        element<T> *new_elem;
        new_elem->next = root;
        root = new_elem;
        size_++;

        return *this;
    }

    element<T> *prev_elem = root;
    element<T> *next_elem;
    for(int i = 0; i < pos - 1; i++)
        prev_elem = prev_elem->next;
    next_elem = prev_elem->next;

    element<T> *new_elem = new element<T>(elem, prev_elem, next_elem);
    prev_elem->next = new_elem;
    next_elem->prev = new_elem;
    size_++;

    return *this;
}

template <class T>
int List<T>::Length()
{
    return size_;
}

template <class T>
int List<T>::Search(T elem)
{
    for(int i = 0; i < size_; i++)
        if((*this)[i] == elem)
            return i;
    
    return -1;
}

template <class T>
void List<T>::Remove(int pos)
{
    if(pos >= size_ || pos < 0)
        exit(2);

    element<T> *curr_elem = root;
    element<T> *prev_elem;
    element<T> *next_elem;
    for(int i = 0; i < pos - 1; i++)
        curr_elem = curr_elem->next;
    if(!pos)
    {
        next_elem = curr_elem->next;
        next_elem->prev = 0;
        root = next_elem;
    }
    else if(pos == size_ - 1)
    {
        prev_elem = curr_elem->prev;
        prev_elem->next = 0;
    }
    else
    {
        prev_elem = curr_elem->prev;
        next_elem = curr_elem->next;
        prev_elem->next = next_elem;
        next_elem->prev = prev_elem;
    }
    
    size_--;
    delete curr_elem;
}

template <class T>
element<T>* List<T>::GetRoot()
{
    return root;
}

template <class T>
int List<T>::GetSize()
{
    return size_;
}

template class List<int>;