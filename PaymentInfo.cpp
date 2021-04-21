#include "PaymentInfo.h"
#include "DynamicCharSetter.h"

PaymentInfo::PaymentInfo()
{
	DynamicCharSetter::setValue(&this->payTo, '\0');
	this->amountOfMoney = 0;
}

PaymentInfo::PaymentInfo(const char* payTo, double amountOfMoney)
{
	DynamicCharSetter::setValue(&this->payTo, payTo);
	this->amountOfMoney = amountOfMoney;
}

PaymentInfo::PaymentInfo(const PaymentInfo& other)
{
	*this = other;
}

PaymentInfo& PaymentInfo::operator=(const PaymentInfo& other)
{
	if (this != &other)
	{
		DynamicCharSetter::setValue(&this->payTo, other.payTo);
		this->amountOfMoney = other.amountOfMoney;
	}
	return *this;
}

PaymentInfo::~PaymentInfo()
{
	delete[] this->payTo;
}

double PaymentInfo::getAmountOfMoney() const
{
	return this->amountOfMoney;
}