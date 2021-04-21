#pragma once
#include "Wallet.h"
#include "Message.h"
#include "Transaction.h"

class User
{
private:
	char* nameOfUser = nullptr;
	char* nameOfBank = nullptr;
	Wallet wallet;

	bool isDepositeValid(Card card, double amountOfMoney) const;
	bool isWithdrawValid(Card* card, double amountOfMoney) const;
	bool isTransferValid(Card* cardFrom, Card* cardTo, double amountOfMoney) const;

	Transaction executeDeposite(Card* card, double amountOfMoney);
	Transaction executeWithdraw(Card* card, double amountOfMoney);
	Transaction executeTransfer(Card* cardFrom, Card* cardTo, double amountOfMoney);

public:
	User();
	User(const char* nameOfUser, const char* nameOfBank);
	User(const User& other);
	~User();
	User& operator=(const User& other);

	const char* getNameOfUser() const;
	const char* getNameOfBank() const;

	void removeWallet();
	void addCardToWallet(Card card);
	void removeCardFromWallet(Card card);

	Message makeDeposite(Card& card, double amountOfMoney);
	Message makeWithdraw(Card& card, double amountOfMoney);
	Message makeTransfer(Card& cardFrom, Card& cardTo, double amountOfMoney);
	Message makePayment(Card& card, PaymentInfo info);

	void printWallet() const;
	void printTransactionHistory() const;
};