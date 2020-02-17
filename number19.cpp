/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
18 January 2019
Annual High Temperatures Program
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	double NYC;
	double denver;
	double phoenix;
	double rise;

	rise = .02;

	NYC = (85 * .02) + 85;
	
	denver = (88 * .02) + 88;

	phoenix = (106 * .02) + 106;

	cout << "***************************************************************************\n"
		<< "The new average July high temperature for New York City is " << NYC << endl
		<< "The new average July high temperature for Denver is " << denver << endl
		<< "The new average July high temperature for Phoenix is " << phoenix << endl
		<< "****************************************************************************\n";

		return 0;
}