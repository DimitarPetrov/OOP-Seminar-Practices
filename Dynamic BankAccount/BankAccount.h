#ifndef BANKACCOUNT_H_BANKACCOUNT
#define BANKACCOUNT_H_BANKACCOUNT

class BankAccount {
private:
	char* name;
	char* accNumber;
	double money;
	void Copy(BankAccount const& acc);
	void Erase();

public:
	BankAccount();
	BankAccount(const char* name, const char* accNumber);
	BankAccount(const char* name, const char* accNumber, double money);
	BankAccount(BankAccount const& acc);
	BankAccount& operator=(BankAccount const& acc);
	const char* getName() const;
	const char* getAccNumber() const;
	double getMoney() const;
	void print() const;
	void read();
	void deposit(double amount);
	bool withdraw(double amount);
	bool transfer(BankAccount& acc, double amount);
	bool richerThan(BankAccount const& acc);
	~BankAccount();
};


#endif