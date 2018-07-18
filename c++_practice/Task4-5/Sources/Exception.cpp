#include "../Headers/Exception.h"

const char * IteratorUndefException::Message()
{
	return "Iterator is not initialized";
}

const char * IteratorBoundsException::Message()
{
	return "Iterator position is out of bounds";
}