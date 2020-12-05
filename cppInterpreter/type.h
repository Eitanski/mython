#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type
{
public:
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
	virtual Type* operator=(const Type& other) = 0;
	void setIsTemp(bool isTemp);
	bool getIsTemp();
	virtual void* getValue() const = 0;

private:
	bool _isTemp = false;
};





#endif //TYPE_H
