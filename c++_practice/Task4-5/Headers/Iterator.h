#pragma once
#include "Exception.h"

template <class T>
class Iterator
{
    public:
        // Переходим к следующему элементу
        virtual bool Next() = 0;
        
        // Возвращаем ссылку на элемент
        virtual T& Key() = 0;
        
        // Возвращаемся в начало списка
        virtual void Reset() = 0; 
};