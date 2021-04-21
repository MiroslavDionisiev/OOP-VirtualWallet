#pragma once
#include "Card.h"

const double MONTHLY_FEE_G = 0.5;
const double ANNUAL_FEE_G = 1.5;
const int LONGEVITY_G = 4;
const double RESERVE_G = 200;

class GoldCard : public Card
{
private:
	int annualFee;
	int monthlyFee;
	//int expireDate;
	double currentReserve;

public:
	GoldCard(const char* nameOfCard);
	GoldCard(const GoldCard& other);
	GoldCard& operator=(const GoldCard& other);

	virtual void deposite(double amount);
	virtual void withdraw(double amount);

	virtual double getCurrentReserve() const;
};

