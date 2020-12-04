#include "NameErrorException.h"


NameErrorException::NameErrorException(const std::string& name) : _name(name)
{

}

const char* NameErrorException::what() const
{
	return std::string("NameError : name '" + _name + "' is not defined").c_str();
}