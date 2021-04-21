#include "Message.h"
#include "DynamicCharSetter.h"
#include <iostream>
using namespace std;

Message::Message()
{
	DynamicCharSetter::setValue(&this->message, '\0');
	this->isActuonValid = false;
}

Message::Message(const char* message, bool isActuonValid)
{
	DynamicCharSetter::setValue(&this->message, message);
	this->isActuonValid = isActuonValid;
}

Message::Message(const Message& other)
{
	*this = other;
}

Message::~Message()
{
	delete[] this->message;
}

Message& Message::operator=(const Message& other)
{
	if (this != &other)
	{
		DynamicCharSetter::setValue(&this->message, other.message);
		this->isActuonValid = other.isActuonValid;
	}
	return *this;
}

void Message::print() const
{
	cout << this->message << endl;
}