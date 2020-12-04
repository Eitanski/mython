#ifndef STRING_H
#define STRING_H

#include "type.h"
#include "Sequence.h"

class String : public Sequence
{
public:
	String(std::string val);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
private:
	std::string _val;
};


#endif // STRING_H