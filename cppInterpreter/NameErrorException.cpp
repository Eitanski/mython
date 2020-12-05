#include "NameErrorException.h"


NameErrorException::NameErrorException(const std::string& name) : _name(name)
{

}

const char* NameErrorException::what() const throw()
{
	_buffer = "NameError : name '" + _name + "' is not defined";
	return _buffer.c_str();
}