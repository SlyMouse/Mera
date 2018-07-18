#include <iostream>
#include "Headers/List.h"
#include "Headers/ForwardIterator.h"
#include "Headers/ReverseIterator.h"

int main()
{
    List<int> list;
    list.Add(1).Add(3).Add(5);
    list.Insert(2, 1).Insert(4, 3);

    if (list.Length() != 5) std::cout<<"bad list\n";
    if (list.Search(4) != 3) std::cout << "bad list\n";

    list.Remove(0);
    if (list[0] != 2) std::cout << "bad list\n";

    ForwardIterator<int> fwdIter(list);
    ReverseIterator<int> revIter(list);

    list.Add(6);

    while (fwdIter.Next())
        std::cout << fwdIter.Key() << " ";
    std::cout << std::endl;

    while (revIter.Next())
        std::cout << revIter.Key() << " ";
    std::cout << std::endl;

    try
    {
        fwdIter.Next();
        std::cout << "Incorrect iterator behavior" << std::endl;
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message() << std::endl;
    }

    try
    {
        fwdIter.Reset();
        fwdIter.Key();
        std::cout << "Incorrect iterator behavior" << std::endl;
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message() << std::endl;
    }
}