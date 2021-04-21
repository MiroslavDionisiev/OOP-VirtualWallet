#include "Transaction.h"
#include <iostream>
#include <cstring>
using namespace std;

Transaction::Transaction()
{
	Card to = Card();
	Card from = Card();
	this->type = TransactionType::none;
}

Transaction::Transaction(Card used, TransactionType type)
{
	if (type == TransactionType::deposite)
	{
		this->from = Card();
		this->to = used;
	}
	else if (type == TransactionType::withdraw)
	{
		this->from = used;
		this->to = Card();
	}
	this->type = type;
}

Transaction::Transaction(Card from, Card to , TransactionType type)
{
	this->from = from;
	this->to = to;
	this->type = type;
}

Transaction::Transaction(Card used, PaymentInfo info)
{
	this->from = used;
	this->to = Card();
	this->info = info;
}

Transaction::Transaction(const Transaction& other)
{
	*this = other;
}

Transaction& Transaction::operator=(const Transaction& other)
{
	if (this != &other)
	{
		this->from = other.from;
		this->to = other.to;
		this->info = other.info;
		this->type = other.type;
	}
	return *this;
}

void Transaction::pushTransactionToFile(ofstream& file)
{
	if (file.is_open())
	{
		if (this->type == TransactionType::deposite)
		{
			file << "Deposite to card " << this->to.getName() << " current balance " << this->to.getCurrentBalance() << endl;
		}
		else if (type == TransactionType::withdraw)
		{
			file << "Withdraw from card " << this->from.getName() << " current balance " << this->from.getCurrentBalance() << endl;
		}
		else if (this->type == TransactionType::transfer)
		{
			file << "Trannsfer from card " << this->from.getName() << " current balance " << this->from.getCurrentBalance() << " to card " << to.getName() << " current balance " << this->to.getCurrentBalance() << endl;
		}
		else
		{
			file << "Payment was executed from " << this->from.getName() << " for " << this->info.getAmountOfMoney() << " the current balance in the card is " << this->from.getCurrentBalance() << endl;
		}
	}
}

void Transaction::print() const
{
	if (this->type == TransactionType::deposite)
	{
		cout << "Deposite to card " << this->to.getName() << " current balance " << this->to.getCurrentBalance() << endl;
	}
	else if (this->type == TransactionType::withdraw)
	{
		cout << "Withdraw from card " << this->from.getName() << " current balance " << this->from.getCurrentBalance() << endl;
	}
	else if (this->type == TransactionType::transfer)
	{
		cout << "Trannsfer from card " << this->from.getName() << " current balance " << this->from.getCurrentBalance() << " to card " << this->to.getName() << " current balance " << this->to.getCurrentBalance() << endl;
	}
	else
	{
		cout << "Payment was executed from " << this->from.getName() << " for " << this->info.getAmountOfMoney() << " the current balance in the card is " << this->from.getCurrentBalance() << endl;
	}
}