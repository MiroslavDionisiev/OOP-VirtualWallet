#include "Wallet.h"
#include <iostream>
#include <fstream>
using namespace std;

Wallet::Wallet()
{
	this->numberOfCards = 0;
	this->cards = nullptr;
	this->numberOfTransactions = 0;
	this->history = nullptr;
}

Wallet::Wallet(const Wallet& other)
{
	*this = other;
}

Wallet::~Wallet()
{
	delete[] this->cards;
	delete[] this->history;
}

Wallet& Wallet::operator=(const Wallet& other)
{
	if (this != &other)
	{
		delete[] this->cards;
		delete[] this->history;
		if (other.cards != nullptr)
		{
			this->cards = new Card[other.numberOfCards];
			for (int i = 0; i < other.numberOfCards; i++)
			{
				cards[i] = other.cards[i];
			}
		}
		else
		{
			this->cards = nullptr;
		}
		if (other.history != nullptr)
		{
			this->history = new Transaction[other.numberOfTransactions];
			for (int i = 0; i < other.numberOfTransactions; i++)
			{
				history[i] = other.history[i];
			}
		}
		else
		{
			this->history = nullptr;
		}
		this->numberOfCards = other.numberOfCards;
		this->numberOfTransactions = other.numberOfTransactions;
	}
	return *this;
}

int Wallet::getIndexOfACard(const char* cardName) const
{
	for (int i = 0; i < this->numberOfCards; i++)
	{
		if (strcmp(this->cards[i].getName(), cardName) == 0)
		{
			return i;
		}
	}
	cout << "No such card found" << endl;
	return -1;
}

void Wallet::setCard(int index, Card* card)
{
	this->cards[index] = *card;
}

bool Wallet::isCardExisting(const char* cardName) const
{
	for (int i = 0; i < this->numberOfCards; i++)
	{
		if (strcmp(this->cards[i].getName(), cardName) == 0)
		{
			return true;
		}
	}
	cout << "No such card found" << endl;
	return false;
}

void Wallet::addCard(Card& newCard)
{
	if (this->numberOfCards < numberOfAllCards)
	{
		Card* tempCards = new Card[this->numberOfCards + 1];
		for (int i = 0; i < this->numberOfCards; i++)
		{
			tempCards[i] = this->cards[i];
		}
		tempCards[this->numberOfCards] = newCard;
		delete[] this->cards;
		this->cards = tempCards;
		this->numberOfCards++;
	}
	else
	{
		cout << "It's full" << endl;
	}
}

void Wallet::removeCard(int index)
{
	if (index < this->numberOfCards)
	{
		Card* tempCards = new Card[this->numberOfCards - 1];
		for (int i = 0; i < index; i++)
		{
			tempCards[i] = this->cards[i];
		}
		for (int i = index + 1; i < this->numberOfCards; i++)
		{
			tempCards[i - 1] = this->cards[i];
		}
		delete[] this->cards;
		this->cards = tempCards;
		this->numberOfCards--;
	}
	else
	{
		cout << "Index out of boundaries" << endl;
	}
}

Card Wallet::findCard(const char* cardName)
{
	for (int i = 0; i < this->numberOfCards; i++)
	{
		if (strcmp(this->cards[i].getName(), cardName) == 0)
		{
			return this->cards[i];
		}
	}
	cout << "No such card found" << endl;
}

void Wallet::addTransaction(Transaction transaction)
{
	Transaction* tempHistory = new Transaction[this->numberOfTransactions + 1];
	for (int i = 0; i < this->numberOfTransactions; i++)
	{
		tempHistory[i] = this->history[i];
	}
	tempHistory[this->numberOfTransactions] = transaction;
	delete[] this->history;
	this->numberOfTransactions++;
	this->history = tempHistory;
}

void Wallet::print() const
{
	for (int i = 0; i < this->numberOfCards; i++)
	{
		cout << this->cards[i].getName() << " " << this->cards[i].getCurrentBalance() << endl;
	}
}

void Wallet::printTransactionHistory() const
{
	for (int i = 0; i < this->numberOfTransactions; i++)
	{
		this->history[i].print();
	}
}

void Wallet::printToFile() const
{
	ofstream file;
	file.open("history.txt", ios::trunc);
	if (file.is_open())
	{
		for (int i = 0; i < this->numberOfTransactions; i++)
		{
			this->history[i].pushTransactionToFile(file);
		}
	}
	file.close();
}