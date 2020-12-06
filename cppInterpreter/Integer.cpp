#include "Integer.h"

Integer::Integer(int val) : _val(val)
{

}

std::string Integer::toString() const
{
	return std::to_string(_val);
}

bool Integer::isPrintable() const
{
	return true;
}

Type* Integer::operator=(const Type& other)
{
	return new Integer(std::stoi(other.toString()));
}
