#include "GoldCard.h"

GoldCard::GoldCard(const char* nameOfCard) : Card(nameOfCard)
{
	this->annualFee = ANNUAL_FEE_G;
	this->monthlyFee = MONTHLY_FEE_G;
	this->currentReserve = RESERVE_G;
}

GoldCard::GoldCard(const GoldCard& other)
{
	*this = other;
}

GoldCard& GoldCard::operator=(const GoldCard& other)
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

void GoldCard::deposite(double amount)
{
	double tempBalance = getCurrentBalance();
	if (this->currentReserve == RESERVE_G)
	{
		tempBalance += amount;
	}
	else
	{
		double toAddToReserve = RESERVE_G - this->currentReserve;
		if (toAddToReserve >= amount)
		{
			this->currentReserve += amount;
		}
		else
		{
			this->currentReserve += toAddToReserve;
			tempBalance += (amount - toAddToReserve);
		}
	}
	setCurrentBalance(tempBalance);
}

void GoldCard::withdraw(double amount)
{
	double tempBalance = getCurrentBalance();
	if (tempBalance >= amount)
	{
		tempBalance -= amount;
	}
	else
	{
		if ((tempBalance + this->currentReserve) >= amount)
		{
			amount -= tempBalance;
			tempBalance = 0;
			this->currentReserve -= amount;
		}
	}
	setCurrentBalance(tempBalance);
}

double GoldCard::getCurrentReserve() const
{
	return this->currentReserve;
}