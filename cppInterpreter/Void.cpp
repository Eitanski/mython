#include "Void.h"

Void::Void() {}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::toString() const
{
	return "";
}

Type* Void::operator=(const Type& other)
{
	return new Void();
}

void* Void::getValue()
{
	return nullptr;
}