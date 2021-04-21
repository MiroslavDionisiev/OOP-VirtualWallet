#pragma once
#include "Card.h"
#include "Transaction.h"

const int numberOfAllCards = 5;

class Wallet
{
private:
	Card* cards;
	int numberOfCards;
	Transaction* history;
	int numberOfTransactions;

public:
	Wallet();
	Wallet(const Wallet& other);
	~Wallet();
	Wallet& operator= (const Wallet& other);

	int getIndexOfACard(const char* cardName) const;

	void setCard(int index, Card* card);

	bool isCardExisting(const char* cardName) const;
	void addCard(Card& newCard);
	void removeCard(int index);
	Card findCard(const char* cardName);

	void addTransaction(Transaction transaction);

	void print() const;
	void printTransactionHistory() const;
	void printToFile() const;
};

