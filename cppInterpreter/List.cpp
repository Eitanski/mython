#include "List.h"

List::List(std::vector<Type*>& vals)
{
	_vals.assign(vals.begin(), vals.end());
}

bool List::isPrintable() const
{
	return true;
}

void* List::getValue() const 
{
	std::vector<Type*>* ret = &_vals;
	return &_vals;
}

std::string List::toString() const
{
	std::string str = "[";

	for (Type* i : _vals)
		str += i->toString() + ",";

	return str.substr(0, str.length() - 1) + "]";
}

Type* List::operator=(const Type& other)
{
	std::vector<Type*>& myName = *reinterpret_cast<std::vector<Type*>*>(other.getValue());
	return new List();
}