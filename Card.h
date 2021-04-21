#pragma once

class Card
{
private:
	char* nameOfCard = nullptr;
	double balance;

public:
	Card();
	Card(const char* nameOfCard);
	Card(const Card& other);
	virtual ~Card();
	Card& operator=(const Card& other);

	virtual void deposite(double amount);
	virtual void withdraw(double amount);

	double getCurrentBalance() const;
	virtual double getCurrentReserve() const;
	const char* getName() const;

	void setCurrentBalance(double amount);
};