/*********************************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
10 January 2020
Integer X Program Program
This program reads in values and calculates the number of values entered, the sum, 
and the average.
***********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ofstream outfile;

int main()
{
	//Open file
	outfile.open("IntegeresReport.txt");

	//Declare Variables 
	int score;
	int total = 0;

	//Read in values
	cin >> score;

	int num;
	num = 0;

	//Calculate until sentinal value 
	while (score != 0)
	{
		total = total + score;

		num++;

		cin >> score;
	}

	//Write report to outfile
	outfile << "Total number of values entered = " << num << endl;
	outfile << "Sum of values = " << total << endl;
	
	//If / else statments to calculate average 
	if (num > 0)

		outfile << "Average is = " << fixed << showpoint << setprecision(1) << total * 1.0 / num << endl;

	else
		outfile << "Average = 0" << endl;

	//Close outfile
	outfile.close();

	//Terminate program 
	return 0;

}
