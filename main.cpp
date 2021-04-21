#include <iostream>
#include "User.h"
#include "StandartCard.h"
#include "GoldCard.h"
using namespace std;

int main()
{
	Message status;
	User user("Someone", "Unicredit");
	StandartCard card1("Card1");
	GoldCard card2("Card2");
	StandartCard card3("Card3");
	user.addCardToWallet(card1);
	user.addCardToWallet(card2);
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	status = user.makeDeposite(card1, 300);
	status.print();
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	status = user.makeDeposite(card1, 100);
	status.print();
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	status = user.makeTransfer(card1, card2, 100);
	status.print();
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	status = user.makeWithdraw(card2, 50);
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	status = user.makePayment(card1, PaymentInfo("Emag", 150));
	user.printWallet();
	user.printTransactionHistory();
	cout << "//////////////////////////" << endl;
	user.removeWallet();
	user.printWallet();
	user.printTransactionHistory();
	return 0;
}