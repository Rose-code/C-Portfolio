/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 January 2019
Stock Commission Program
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double price;
	double shares;
	double commission;
	double paid;
	double commissionAmount;
	double total;

	cout << "*************************************\n"
		<< "How many shares were bought?\n"
		<< "*************************************\n";
	cin >> shares;

	cout << "*******************************\n"
		<< "What is the price per share?\n"
		<< "********************************\n";
	cin >> price;

	cout << "**************************************************************\n"
		<< "What is the commission in decimal form owed to the stockbroker\n"
		<< "***************************************************************\n";
	cin >> commission;

	paid = shares * price;

	cout << "************************************************\n"
		<< "The amount paid for the stock is $" << paid << endl
		<< "*************************************************\n";

	commissionAmount = paid * commission;

	cout << "********************************************************\n"
		<< "The amount of the commission is $" << commissionAmount << endl
		<< "*********************************************************\n";

	total = paid + commissionAmount;

	cout << "*************************************************\n"
		<< "The total amount paid with commission is $" << total << endl
		<< "**************************************************\n";

	return 0;

}