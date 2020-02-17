/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 January 2019
Average Rainfall Input Program
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string month1;
	string month2;
	string month3;
	double inches1;
	double inches2;
	double inches3;
	double average;

	cout << "******************************************\n"
		<< "Please enter the name of the first month\n"
		<< "******************************************\n";
	cin >> month1;

	cout << "*******************************************************************\n"
		<< "Please enter the amount of rainfall (in inches) in the first month\n"
		<< "********************************************************************\n";
	cin >> inches1;

	cout << "******************************************\n"
		<< "Please enter the name of the second month\n"
		<< "******************************************\n";
	cin >> month2;

	cout << "*******************************************************************\n"
		<< "Please enter the amount of rainfall (in inches) in the second month\n"
		<< "********************************************************************\n";
	cin >> inches2;

	cout << "******************************************\n"
		<< "Please enter the name of the third month\n"
		<< "******************************************\n";
	cin >> month3;

	cout << "*******************************************************************\n"
		<< "Please enter the amount of rainfall (in inches) in the third month\n"
		<< "********************************************************************\n";
	cin >> inches3;

	average = (inches1 + inches2 + inches3) / 3;

	cout << "**************************************************************************\n"
		<< "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << setprecision(2) << fixed << showpoint  << average << " inches\n"
		<< "**************************************************************************\n";

	return 0;






}