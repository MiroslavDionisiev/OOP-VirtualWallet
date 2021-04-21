#pragma once
#include "Card.h"

class PaymentInfo
{
private:
	char* payTo = nullptr; // owner for name
	double amountOfMoney;

public:
	PaymentInfo();
	PaymentInfo(const char* payTo, double amountOfMoney);
	PaymentInfo(const PaymentInfo& other);
	PaymentInfo& operator=(const PaymentInfo& other);
	~PaymentInfo();

	double getAmountOfMoney() const;
};

// от сметка в смекта или към сайт