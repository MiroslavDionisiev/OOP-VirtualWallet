#include "Card.h"
#include "DynamicCharSetter.h"
#include <iostream>
using namespace std;

Card::Card()
{
	DynamicCharSetter::setValue(&this->nameOfCard, '\0');
	this->balance = 0;
}

Card::Card(const char* nameOfCard)
{
	DynamicCharSetter::setValue(&this->nameOfCard, nameOfCard);
	this->balance = 0;
}  

Card::Card(const Card& other)
{
	*this = other;
}

Card::~Card()
{
	delete[] this->nameOfCard;
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		DynamicCharSetter::setValue(&this->nameOfCard, other.nameOfCard);
		this->balance = other.balance;
	}
	return *this;
}

void Card::deposite(double amount)
{
	return;
}

void Card::withdraw(double amount)
{
	return;
}

double Card::getCurrentBalance() const
{
	return this->balance;
}

double Card::getCurrentReserve() const
{
	return 0;
}

const char* Card::getName() const
{
	return this->nameOfCard;
}

void Card::setCurrentBalance(double amount)
{
	this->balance = amount;
}