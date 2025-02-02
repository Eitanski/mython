#include "Boolean.h"

Boolean::Boolean(bool val) : _val(val)
{
	
}

std::string Boolean::toString() const
{
	return _val ? "True" : "False";
}

bool Boolean::isPrintable() const
{
	return true;
}

Type* Boolean::operator=(const Type& other)
{
	return new Boolean(other.toString() == "True");
}

