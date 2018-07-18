#include "Iterator.h"
#include "List.h"

template <class T>
class ForwardIterator : public Iterator<T>
{
    public:
        ForwardIterator(List<T> &list);
        bool Next();
        T& Key();
        void Reset();
    private:
        List<T> &list_;
        int curr_pos_ = -1;
};