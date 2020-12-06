#ifndef VOID_H
#define VOID_H

#include<string>
#include "type.h"

class Void : public Type
{
public:
	Void();
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual Type* operator=(const Type& other);
private:
};

#endif // VOID_H