#include "stdafx.h"
#include "BankAccount.h"
#include <cstring>
#include <iostream>
#include <cassert>

BankAccount::BankAccount() : money(0), name(nullptr), accNumber(nullptr) {}

BankAccount::BankAccount(const char* name, const char* accNumber) : money(0) {
	this->name = new char[strlen(name) + 1];
	assert(name != nullptr);
	strcpy_s(this->name, strlen(name) + 1, name);
	this->accNumber = new char[strlen(accNumber) + 1];
	assert(accNumber != nullptr);
	strcpy_s(this->accNumber, strlen(accNumber) + 1, accNumber);
}

BankAccount::BankAccount(const char* name, const char* accNumber, double money) : money(money) {
	this->name = new char[strlen(name) + 1];
	assert(name != nullptr);
	strcpy_s(this->name, strlen(name) + 1, name);
	this->accNumber = new char[strlen(accNumber) + 1];
	assert(accNumber != nullptr);
	strcpy_s(this->accNumber, strlen(accNumber) + 1, accNumber);
}

BankAccount::BankAccount(BankAccount const& acc) {
	Copy(acc);
}

BankAccount& BankAccount::operator=(BankAccount const& acc) {
	if (this != &acc) {
		Erase();
		Copy(acc);
	}
	return *this;
}

const char* BankAccount::getName() const {
	return name;
}

const char* BankAccount::getAccNumber() const {
	return accNumber;
}

double BankAccount::getMoney() const {
	return money;
}

void BankAccount::print() const {
	std::cout << name << "\n" << accNumber << "\n" << money << std::endl;
}

void BankAccount::read() {
	char buffer[1024];
	std::cin.getline(buffer, 1024);
	if (name == nullptr) {
		name = new char[strlen(buffer) + 1];
		strcpy_s(name, strlen(buffer) + 1, buffer);
	}
	std::cin.getline(buffer, 1024);
	if (accNumber == nullptr) {
		accNumber = new char[strlen(buffer) + 1];
		strcpy_s(accNumber, strlen(buffer) + 1, buffer);
	}
	std::cin >> money;
	std::cin.ignore();
}

void BankAccount::deposit(double amount) {
	money += amount;
}

bool BankAccount::withdraw(double amount) {
	if (money < amount) {
		std::cout << "Don't have enough money!";
		return false;
	}
	money -= amount;
	return true;
}

bool BankAccount::transfer(BankAccount& acc, double amount) {
	if (withdraw(amount)) {
		acc.deposit(amount);
		return true;
	}
	return false;
}

bool BankAccount::richerThan(BankAccount const& acc) {
	if (money > acc.money) {
		return true;
	}
	return false;
}

void BankAccount::Copy(BankAccount const& acc) {
	this->name = new char[strlen(acc.name) + 1];
	assert(name != nullptr);
	strcpy_s(name, strlen(acc.name) + 1, acc.name);
	this->accNumber = new char[strlen(acc.accNumber) + 1];
	assert(accNumber != nullptr);
	strcpy_s(accNumber, strlen(acc.accNumber) + 1, acc.accNumber);
	this->money = acc.money;

}

void BankAccount::Erase() {
	delete[] name;
	delete[] accNumber;
}


BankAccount::~BankAccount(){
	Erase();
}
