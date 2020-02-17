/***********************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
24 October 2019
Recursion Root
This program uses a recursive function to calculate the nth root of a 
finite set of numbers and display the root report to a file
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

ofstream outfile;

//Prototypes
double nthRoot(int a, int n, double guess);

int main()
{
	//open file
	outfile.open("RootReport.txt");

	outfile << "*********************ROOT REPORT*********************\n";

	//nested loop to print root values
	for (int a = 2; a <= 40; a++)
	{
		for (int n = 2; n <= 10; n++)
		{
			outfile << setw(10) << setprecision(5) << fixed << nthRoot(a, n, 1);
		}
		outfile << endl;
	}

	//close file
	outfile.close();

	//terminate program
	return 0;
}

//recursive function to calculate roots 
double nthRoot(int a, int n, double guess)
{
	//base case
	if (abs(a - pow(guess, n)) < .00001)
	{
		return guess;
	}

	else //recursive call
		return nthRoot(a, n, (1.0 / n) *((n - 1) * guess * 1.0 + a * 1.0 / (pow(guess, n - 1))));
}
