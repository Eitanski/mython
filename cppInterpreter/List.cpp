#include "List.h"
#include "Helper.h"
#include "Parser.h"

List::List(std::vector<Type*> vals)
{
	_vals = vals;
}

bool List::isPrintable() const
{
	return true;
}

std::vector<Type*>& List::getVals()
{
	return _vals;
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
	return (Type*)&other;
}

std::vector<Type*> List::getList(std::string s)
{
	std::string tmp = s.substr(1, s.length() - 2);
	std::string sub;
	int pos = 0, len = 0;

	std::vector<Type*> vec;

	while (pos < tmp.length())
	{
		len = tmp.find(',', pos);
		if (len == -1) len = tmp.length();
		len -= pos;
		sub = tmp.substr(pos, len);
		vec.push_back(Parser::getType(sub));
		Helper::trim(sub);
		pos += len + 1;
	}

	return vec;
}