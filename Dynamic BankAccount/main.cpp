// ConsoleApplication39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BankAccount.h"

int main(){
	int n;
	std::cin >> n;
	std::cin.ignore();
	BankAccount* arr = new BankAccount[n];
	for (int i = 0; i < n; ++i) {
		arr[i].read();
	}
	BankAccount max = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i].richerThan(max)) {
			max = arr[i];
		}
	}
	max.print();
    return 0;
}

