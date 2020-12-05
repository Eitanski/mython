#ifndef LIST_H
#define LIST_H

#include "Sequence.h"
#include <vector>

class List : public Sequence
{
public:
	List(std::vector<Type*>& vals);
	std::vector<Type*>& getVals();
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual Type* operator=(const Type& other);
	virtual void* getValue() const;

private:
	std::vector<Type*> _vals;
};



#endif // LIST_H