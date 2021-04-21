#include "User.h"
#include "DynamicCharSetter.h"
#include "Wallet.h"
#include <iostream>
using namespace std;

User::User()
{
	DynamicCharSetter::setValue(&this->nameOfUser, '\0');
	DynamicCharSetter::setValue(&this->nameOfBank, '\0');
}

User::User(const char* nameOfUser, const char* nameOfBank)
{
	DynamicCharSetter::setValue(&this->nameOfUser, nameOfUser);
	DynamicCharSetter::setValue(&this->nameOfBank, nameOfBank);
}

User::User(const User& other)
{
	*this = other;
}

User::~User()
{
	delete[] this->nameOfUser;
	delete[] this->nameOfBank;
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		DynamicCharSetter::setValue(&this->nameOfUser, other.nameOfUser);
		DynamicCharSetter::setValue(&this->nameOfBank, other.nameOfBank);
		this->wallet = other.wallet;
	}
	return *this;
}

bool User::isDepositeValid(Card card, double amountOfMoney) const
{
	if ((this->wallet.isCardExisting(card.getName()) == true) && (amountOfMoney >= 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool User::isWithdrawValid(Card* card, double amountOfMoney) const
{
	if ((this->wallet.isCardExisting(card->getName()) == true) && (amountOfMoney >= 0))
	{
		if ((card->getCurrentBalance() + card->getCurrentReserve()) >= amountOfMoney)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool User::isTransferValid(Card* cardFrom, Card* cardTo, double amountOfMoney) const
{
	if ((this->wallet.isCardExisting(cardFrom->getName()) == true) && (this->wallet.isCardExisting(cardTo->getName()) == true) && (amountOfMoney >= 0))
	{
		if ((cardFrom->getCurrentBalance() + cardFrom->getCurrentReserve()) >= amountOfMoney)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

Transaction User::executeDeposite(Card* card, double amountOfMoney)
{
	card->deposite(amountOfMoney);
	Wallet wallet = this->wallet;
	wallet.setCard(this->wallet.getIndexOfACard(card->getName()), card);
	this->wallet = wallet;
	return Transaction(*card, TransactionType::deposite);
}

Transaction User::executeWithdraw(Card* card, double amountOfMoney)
{
	card->withdraw(amountOfMoney);
	Wallet wallet = this->wallet;
	wallet.setCard(this->wallet.getIndexOfACard(card->getName()), card);
	this->wallet = wallet;
	return Transaction(*card, TransactionType::withdraw);
}

Transaction User::executeTransfer(Card* cardFrom, Card* cardTo, double amountOfMoney)
{
	cardFrom->withdraw(amountOfMoney);
	cardTo->deposite(amountOfMoney);
	Wallet wallet = this->wallet;
	wallet.setCard(this->wallet.getIndexOfACard(cardFrom->getName()), cardFrom);
	wallet.setCard(this->wallet.getIndexOfACard(cardTo->getName()), cardTo);
	this->wallet = wallet;
	return Transaction(*cardFrom, *cardTo, TransactionType::transfer);
}

const char* User::getNameOfUser() const
{
	return this->nameOfUser;
}

const char* User::getNameOfBank() const
{
	return this->nameOfBank;
}

void User::removeWallet()
{
	Wallet wallet;
	this->wallet = wallet;
}

void User::addCardToWallet(Card card)
{
	this->wallet.addCard(card);
}

void User::removeCardFromWallet(Card card)
{
	int index = this->wallet.getIndexOfACard(card.getName());
	if (index < 0)
	{
		cout << "Invalid index" << endl;
		return;
	}
	this->wallet.removeCard(index);
}

Message User::makeDeposite(Card& card, double amountOfMoney)
{
	Transaction example;
	Card* cardt = &card;
	*cardt = this->wallet.findCard(cardt->getName());
	if (isDepositeValid(*cardt, amountOfMoney) == false)
	{
		return Message("Deposite failed.", false);
	}
	example = executeDeposite(cardt, amountOfMoney);
	this->wallet.addTransaction(example);
	this->wallet.printToFile();
	return Message("Successful deposite.", true);
}

Message User::makeWithdraw(Card& card, double amountOfMoney)
{
	Transaction example;
	Card* cardt = &card;
	*cardt = this->wallet.findCard(cardt->getName());
	if (isWithdrawValid(cardt, amountOfMoney) == false)
	{
		return Message("Withdraw failed.", false);
	}
	example = executeWithdraw(cardt, amountOfMoney);
	this->wallet.addTransaction(example);
	this->wallet.printToFile();
	return Message("Successful withdraw.", true);
}

Message User::makeTransfer(Card& cardFrom, Card& cardTo, double amountOfMoney)
{
	Transaction example;
	Card* cardtFrom = &cardFrom;
	Card* cardtTo = &cardTo;
	*cardtFrom = this->wallet.findCard(cardtFrom->getName());
	*cardtTo = this->wallet.findCard(cardtTo->getName());
	if (isTransferValid(cardtFrom, cardtTo, amountOfMoney) == false)
	{
		return Message("Transfer failed.", false);
	}
	example = executeTransfer(cardtFrom, cardtTo, amountOfMoney);
	this->wallet.addTransaction(example);
	this->wallet.printToFile();
	return Message("Successful transfer.", true);
}

Message User::makePayment(Card& card, PaymentInfo info)
{
	Transaction example;
	Card* cardt = &card;
	*cardt = this->wallet.findCard(cardt->getName());
	if (isWithdrawValid(cardt, info.getAmountOfMoney()) == false)
	{
		return Message("Withdraw failed.", false);
	}
	example = executeWithdraw(cardt, info.getAmountOfMoney());
	example = Transaction(*cardt, info);
	this->wallet.addTransaction(example);
	this->wallet.printToFile();
	return Message("Successful payment.", true);
}

void User::printWallet() const
{
	cout << getNameOfUser() << " " << getNameOfBank() << endl;
	this->wallet.print();
}

void User::printTransactionHistory() const
{
	this->wallet.printTransactionHistory();
}