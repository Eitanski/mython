#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include "type.h"

class Integer : public Type
{
public:
	Integer(int val);
	virtual bool isPrintable() const;
	virtual std::string toString() const;

private:
	int _val;
};



#endif // INTEGER_H