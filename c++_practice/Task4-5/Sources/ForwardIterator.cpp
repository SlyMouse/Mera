#include "../Headers/ForwardIterator.h"

template<class T>
ForwardIterator<T>::ForwardIterator(List<T> &list) : list_(list) {}

template <class T>
bool ForwardIterator<T>::Next()
{
    if(curr_pos_ < list_.GetSize() - 1)
    {
        curr_pos_++;
        return true;
    }
    if(curr_pos_ == list_.GetSize() - 1)
    {
        curr_pos_++;
        return false;
    }
    
    throw IteratorBoundsException();
}

template <class T>
T& ForwardIterator<T>::Key()
{
    if(curr_pos_ == list_.GetSize())
        throw IteratorBoundsException();
    if(curr_pos_ == -1)
        throw IteratorUndefException();
    
    return list_[curr_pos_];
}

template <class T>
void ForwardIterator<T>::Reset()
{
    curr_pos_ = -1;
}

template class ForwardIterator<int>;