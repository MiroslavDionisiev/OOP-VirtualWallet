#pragma once
#include "Card.h"
#include "PaymentInfo.h"

class Message
{
private:
	char* message = nullptr;
	bool isActuonValid;

public:
	Message();
	Message(const char* message, bool isActuonValid);
	Message(const Message& other);
	~Message();
	Message& operator=(const Message& other);

	void print() const;
};

