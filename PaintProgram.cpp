/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 January 2019
How Much Paint Program
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double perGallon;
	int gallonsNeeded;
	double coats;
	double height;
	double length;

	cout << "**********************************************************\n"
		<< "How many square feet per gallon does the paint brand cover?\n"
		<< "**********************************************************\n";
	cin >> perGallon;

	cout << "**********************************************************\n"
		<< "How many coats will be painted on the fence?\n"
		<< "**********************************************************\n";
	cin >> coats;

	cout << "**********************************************************\n"
		<< "What is the height of the fence in feet?\n"
		<< "**********************************************************\n";
	cin >> height;

	cout << "**********************************************************\n"
		<< "What is the length of the fence in feet?\n"
		<< "**********************************************************\n";
	cin >> length;

	gallonsNeeded = (height * length * coats) / perGallon;

	cout << "**********************************************************\n"
		<< "Approximately " << gallonsNeeded << " gallons are needed to paint the fence\n"
		<< "**********************************************************\n";


	return 0;



}