#pragma once

class IteratorException
{
    public:
	    virtual const char * Message() = 0;
};

class IteratorUndefException: public IteratorException 
{
    public:
	    const char * Message();
};

class IteratorBoundsException: public IteratorException 
{
    public:
	    const char * Message();
};