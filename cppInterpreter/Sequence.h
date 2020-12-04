#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<string>
#include "type.h"

class Sequence : public Type
{
public:
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

private:


};

#endif // SEQUENCE_H