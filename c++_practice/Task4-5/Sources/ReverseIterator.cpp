#include "../Headers/ReverseIterator.h"

template<class T>
ReverseIterator<T>::ReverseIterator(List<T> &list) : list_(list) {}

template <class T>
bool ReverseIterator<T>::Next()
{
    if(curr_pos_ == -2)
        curr_pos_ = list_.GetSize();
    if(curr_pos_ > 0)
    {
        curr_pos_--;
        return true;
    }
    if(curr_pos_ == 0)
    {
        curr_pos_--;
        return false;
    }
    
    throw IteratorBoundsException();
}

template <class T>
T& ReverseIterator<T>::Key()
{
    if(curr_pos_ == -1)
        throw IteratorBoundsException();
    if(curr_pos_ == list_.GetSize())
        throw IteratorUndefException();
    
    return list_[curr_pos_];
}

template <class T>
void ReverseIterator<T>::Reset()
{
    curr_pos_ = -2;
}

template class ReverseIterator<int>;