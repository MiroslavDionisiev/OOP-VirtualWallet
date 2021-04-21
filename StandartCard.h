#pragma once
#include "Card.h"

const int MONTHLY_FEE = 1;
const int ANNUAL_FEE = 3;
const int LONGEVITY = 3;
const double RESERVE = 0;

class StandartCard : public Card
{
private:
	int annualFee;
	int monthlyFee;
	double currentReserve;

public:
	StandartCard(const char* nameOfCard);
	StandartCard(const StandartCard& other);
	StandartCard& operator=(const StandartCard& other);

	virtual void deposite(double amount);
	virtual void withdraw(double amount);

	virtual double getCurrentReserve() const;
};