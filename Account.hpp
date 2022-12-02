/*
Author: Laureano Banegas
Course: CSCI135
Instructor: Genady Maryash
Assignment: Project 3 Task 1

This program uses the class Account to do multiple things. Default values for first/last name are "anonymous"
Default pin is "0000", the account number is a randomly generated 8-digit number, balance is set to 0.
This program also allows the user to create a transaction, taking in the amount as an integer parameter
if the transaction is negative the program prints "ERROR" and returns false, not allowing the user to 
continue the transaction. Otherwise, the amount is added to the balance, subtracted if it's a negative number.
*/
#pragma once
#include <iostream>
#include <string>

class Account
{
private:
	std::string generateAccountNumber();

	std::string first_name;
	std::string last_name;
	std::string acc_num = generateAccountNumber();
	std::string pin_num;
	int balance;

public:
	//Default Constructor
	Account();

	//Parameterized Constructor
	Account(std::string first_name, std::string last_name, std::string pin);

	//Get
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getAccountNumber() const;
	const std::string& getPin() const;
	const int& getBalance() const;

	//Set
	void setFirstName(std::string new_first);
	void setLastName(std::string new_last);
	bool setPin(std::string new_pin);

	//Transaction
	bool transaction(int amount);
};

