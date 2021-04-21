#include "StandartCard.h"

StandartCard::StandartCard(const char* nameOfCard) : Card(nameOfCard)
{
	this->annualFee = ANNUAL_FEE;
	this->monthlyFee = MONTHLY_FEE;
	this->currentReserve = RESERVE;
}

StandartCard::StandartCard(const StandartCard& other)
{
	*this = other;
}

StandartCard& StandartCard::operator=(const StandartCard& other)
{
	if (this != &other)
	{
		this->annualFee = other.annualFee;
		this->monthlyFee = other.monthlyFee;
		this->currentReserve = other.currentReserve;
		Card::operator=(other);
	}
	return *this;
}

void StandartCard::deposite(double amount)
{
	double tempBalance = getCurrentBalance() + amount;
	setCurrentBalance(tempBalance);
}

void StandartCard::withdraw(double amount)
{
	double tempBalance = getCurrentBalance() - amount;
	setCurrentBalance(tempBalance);
}

double StandartCard::getCurrentReserve() const
{
	return this->currentReserve;
}