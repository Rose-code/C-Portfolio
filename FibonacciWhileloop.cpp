/*******************************************************************************
Morgan Hughes
01/08/2020
CS 318
Dr. Brady Rimes
Fibonacci Sequence Sum Program
This program calculates the growth rate of the crud population based on the
formula of the fibonacci sequence after an alotted amount of time (input).
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 

using namespace std;

ofstream outfile; //declare output file

int main()
{
	//Open report file
	outfile.open("FibonacciWhileReport.txt");

	//declare variables 
	int fib1 = 0; //first # in fibonacci sequence 
	int fib2 = 10; //2nd # in fib sequence 
	int nextFib; //next # in fib sequence 
	int days; //alotted time to be input by user for total after
	int growthTime = 5; //variable for growth rate of crud


	cout << "**********************************************************\n"
		<< "Please enter the amount of days for population calculation\n"
		<< "**********************************************************\n";
	cin >> days;

	//counter variable to be incremented over time period - to calc implement formula 
	int count = days / growthTime;


	//2nd loop: While loop
	int x = 1;
	while (x < count)
	{
		nextFib = fib1 + fib2;
		fib1 = fib2;
		fib2 = nextFib;
		x++;
	}

	outfile << "The crud population after " << days << " days is " << fib2 << endl;

	outfile.close(); //must flush out buffers

	return 0; //terminate program 


}