#pragma once
#include <fstream>
#include "PaymentInfo.h"					

enum class TransactionType
{
	deposite,
	withdraw,
	transfer,
	none
};

class Transaction
{
private:
	TransactionType type;
	Card to; 
	Card from; 
	PaymentInfo info;

public:
	Transaction();
	Transaction(Card used,  TransactionType type);
	Transaction(Card to, Card from,  TransactionType type);
	Transaction(Card used, PaymentInfo info);
	Transaction(const Transaction& other);
	Transaction& operator=(const Transaction& other);

	void pushTransactionToFile(std::ofstream& file);

	void print() const;
};

