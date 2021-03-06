// 450 ATM Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	//Create an ATMM!
	bool continueWithdraw = true; //Used for loop to request more money
	do {
		int toWithdraw = 0; //Used to set amount requested for withdrawal
		//Next few int variables used to keep track of how many bills of each denomination are needed
		int bill50 = 0;
		int bill25 = 0;
		int bill10 = 0;
		int bill5 = 0;
		int bill1 = 0;
		//Next bit asks for how much to withdraw, then figures out how many of each bill to give
		cout << "Welcome to Noah Bank's ATM! How much money would you like to withdraw? You may enter a number between 1 and 300, or just type 0 to exit." << endl;
		cin >> toWithdraw;
		if ((toWithdraw < 1 || toWithdraw > 300) && toWithdraw != 0) {
			do {
				cout << "Sorry, you cannot request an amount less than 1 or greater than 300. Please enter another number, or 0 to exit." << endl;
				cin >> toWithdraw;
			} while (toWithdraw < 1 || toWithdraw > 300);
		}
		else if (toWithdraw == 0) {
			continueWithdraw = false;
			break;
		}
		for (int amountLeft = toWithdraw; amountLeft > 0; ) {
			if (amountLeft >= 50) {
				bill50++;
				amountLeft = amountLeft - 50;
			}
			else if (amountLeft >= 25) {
				bill25++;
				amountLeft = amountLeft - 25;
			}
			else if (amountLeft >= 10) {
				bill10++;
				amountLeft = amountLeft - 10;
			}
			else if (amountLeft >= 5) {
				bill5++;
				amountLeft = amountLeft - 5;
			}
			else if (amountLeft >= 1) {
				bill1++;
				amountLeft = amountLeft - 1;
			}
		}
		//Next we display how many bills the user will receive, avoiding display of bills that we give 0 of
		cout << "Thank you! Your withdrawal will be output as follows:" << endl;
		if (bill50 >= 1) {
			cout << "$50 bill(s) received: " << bill50 << endl;
		}
		if (bill25 >= 1) {
			cout << "$25 bill(s) received: " << bill25 << endl;
		}
		if (bill10 >= 1) {
			cout << "$10 bill(s) received: " << bill10 << endl;
		}
		if (bill5 >= 1) {
			cout << "$5 bill(s) received: " << bill5 << endl;
		}
		if (bill1 >= 1) {
			cout << "$1 bill(s) received: " << bill1 << endl;
		}
	} while (continueWithdraw == true);
	//After the user is done, we thank them and shut down.
	cout << "Thank you for your transaction! Have a great day.";
    return 0;
}

