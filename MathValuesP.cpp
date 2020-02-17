/*********************************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
18 June 2019
Math Values Program
This program calculates a math table for the values of x, including its square, 
square root, and fibonnaci number
***********************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

ofstream outfile;

//Prototypes
int squareNumber(int x);
double squareRoot(int x);
int fib(int x);

int main()
{
	//Open file
	outfile.open("FibCalcReport.txt");

	outfile << "X Square Root Fibonaci\n";
	
	for (int i = 1; i <= 42; i++)
	{
		if (i % 10 == 0)
			outfile << "X Square Root Fibbonaci\n";
		outfile << i << " " << squareNumber(i);
		outfile << " " << fixed << setprecision(6) << squareRoot(i)
			<< " " << fib(i) << endl;
	}

	outfile.close();
	return 0;
}

//Get square of X
int squareNumber(int x)
{
	return x * x;
}

//Get square root of X
double squareRoot(int x)
{
	return sqrt(x);
}

//Calculate Fibbonaci number with given formula 
int fib(int x)
{
	if (x <= 0)
		return 0;
	int val = sqrt(5) / 5 * (pow((1 + sqrt(5)) / 2.0, x) - pow((1 - sqrt(5)) / 2.0, x));
	
	return val;
}
