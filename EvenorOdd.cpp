/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 February 2019
Even or Odd Program
This program calculates 
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

ofstream outfile;

int main
{
	//Declare Variables
	int valueN;
    int even;
	int odd;
	int numType;
	int sum;
	int i;

	i = 0;

	cout << "**************************************************************\n"
		<< "Please enter if you would like to add either odds or evens\n";
	cin >> numType;
	
	cout << "**************************************************************\n"
		<< "Please enter the stopping value N you wish to use for testing\n";
	cin >> valueN;

	while(valueN % 2 == 0)
	{
		sum += i;
	}
	

	while (valueN != % 2 == 0)
	{
		sum += 1;
	}
     

	return 0;

}