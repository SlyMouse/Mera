#include "Iterator.h"
#include "List.h"

template <class T>
class ReverseIterator : public Iterator<T>
{
    public:
        ReverseIterator(List<T> &list);
        bool Next();
        T& Key();
        void Reset();
    private:
        List<T> &list_;
        int curr_pos_ = -2;
};