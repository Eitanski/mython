#include "parser.h"
#include <iostream>
#include "IndentationException.h"
#include "SyntaxException.h"
#include "String.h"
#include "Helper.h"
#include "Integer.h"
#include "Boolean.h"
#include <unordered_map>
#include "Void.h"
#include "NameErrorException.h"

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str) throw()
{
	if (str == "") return nullptr;

	Helper::rtrim(str);

	if (str[0] == ' ' || str[0] == '\t')
	{
		throw IndentationException();
	}

	if (makeAssignment(str)) return new Void();

	Type* type = getType(str);

	if (type == nullptr)
	{
		throw SyntaxException();
	}
	
	if(type->isPrintable())
	{
		std::cout << str << std::endl;
	}

	return type;
}

Type* Parser::getType(std::string& str)	 
{
	if (Helper::isString(str))
	{
		return new String(str);
	}
	if (Helper::isInteger(str))
	{
		return new Integer(std::stoi(str));
	}
	if (Helper::isBoolean(str))
	{
		return new Boolean(str == "True");
	}
	return nullptr;
}

bool Parser::isLegalVarName(const std::string& str)
{
	if (Helper::isDigit(str[0])) return false;
	
	for (std::string::const_iterator i = str.begin(); i != str.end(); i++)
	{
		if (!(Helper::isDigit(*i) || Helper::isLetter(*i) || *i == '_')) return false;
	}
	
	return true;
}

bool Parser::makeAssignment(const std::string& str)
{
	if (std::count(str.begin(), str.end(), '=') != 1)
	{
		throw SyntaxException();
		return false;
	}

	std::string left = str.substr(0, str.find('='));
	std::string right = str.substr(str.find('=') + 1);

	Helper::rtrim(left);
	Helper::ltrim(right);

	if (!isLegalVarName(left))
	{
		throw SyntaxException();
		return false;
	}

	if (!(Helper::isBoolean(right) || Helper::isInteger(right) || Helper::isString(right)))
	{
		throw SyntaxException();
		return false;
	}
	
	std::string val = str;
	_variables[str] = getType(val);

	return true;
}

Type* Parser::getVariableValue(const std::string& str)
{
	if (_variables.find(str) == _variables.end())
	{
		throw NameErrorException(str);
	}

	return _variables[str];
}