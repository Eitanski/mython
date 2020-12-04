#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <string>
#include "type.h"

class Boolean : public Type
{
public:
	Boolean(bool val);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	bool _val;
};




#endif // BOOLEAN_H