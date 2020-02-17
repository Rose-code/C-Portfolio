/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 January 2019
Energy Drink Consumption Program
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double customers;
	double percentP;
	double preferP;
	double approxC;
	double approxc;

	cout << "*************************************\n"
		<< "How many customers were surveyed?\n"
		<< "*************************************\n";
	cin >> customers;

	cout << "**********************************************************************************\n"
		<< "What percent, in decimal form, of those surveyed purchase one or more drinks a week?\n"
		<< "**********************************************************************************\n";
		cin >> percentP;

		cout << "*****************************************************************\n"
			<< "Approximately, in decimal form, how many prefer citrus flavored?\n"
			<< "******************************************************************\n";
		cin >> preferP;

		approxC = customers * percentP;

		cout << "*********************************************************************************************************\n"
			<< "The approximate number of customers in the survey who purchase one or more drinks per week is " << approxC << endl
			<< "*********************************************************************************************************\n";
		
		approxc = customers * preferP;
	cout << "*********************************************************************************************************\n"
		<< "The approximate number of customers in the survey who prefer citrus are " << approxc << endl
		<< "*********************************************************************************************************\n";

	return 0;

}