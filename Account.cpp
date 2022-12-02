#include "Account.hpp"

//Generate acc num func

std::string Account::generateAccountNumber() {
	std::string an_str = "";
	for (int i{ 0 }; i < 8; i++) {
		int temp = rand() % 10;
		an_str += std::to_string(temp);
	}
	return an_str;
}

//Default values

Account::Account()
{
	first_name = "anonymous";
	last_name = "anonymous";
	pin_num = "0000";
	acc_num = generateAccountNumber();
	balance = 0;
}

//Parameterized constructors(3) with default acc num and balance

Account::Account(std::string first_name, std::string last_name, std::string pin_num) {
	this->first_name = first_name;
	this->last_name = last_name;
	if (pin_num.length() == 4) {
		this->pin_num = pin_num;
	}
	else
		pin_num = "0000";
	acc_num = generateAccountNumber();
	balance = 0;
}

/////////////////
//MUTATORS(SET)//
/////////////////

void Account::setFirstName(std::string new_first)
{
	first_name = new_first;
}

void Account::setLastName(std::string new_last)
{
	last_name = new_last;
}

bool Account::setPin(std::string new_pin)
{
	if (pin_num.length() == 4) {
		pin_num = new_pin;
		return true;
	}
	else
		return false;
}

/////////////////
//ACCESORS(GET)//
/////////////////

const std::string& Account::getFirstName() const
{
	return this->first_name;
}
const std::string& Account::getLastName() const
{
	return this->last_name;
}
const std::string& Account::getAccountNumber() const
{
	return this->acc_num;
}
const std::string& Account::getPin() const
{
	return this->pin_num;
}
const int& Account::getBalance() const
{
	return this->balance;
}

////////////////
//TRANSACTIONS//
////////////////

bool Account::transaction(int amount)
{
	if (amount >= 0) {
		balance += amount;
		return true;
	}
	else if (amount < 0) {
		if (balance + amount < 0) {
			std::cout << "ERROR";
			return false;
		}
		else
			balance += amount;
			return true;
	}
		return false;
}