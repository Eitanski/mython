#include "String.h"

String::String(std::string val) : _val(val)
{

}

std::string String::toString() const
{
	return "'" + _val + "'";
}


bool String::isPrintable() const
{
	return true;
}

Type* String::operator=(const Type& other)
{
	return new String(other.toString());
}

void* String::getValue()
{
	return &_val;
}