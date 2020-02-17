/*****************************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
8 February 2019
Minimum and Maximum Program
This program asks the user to enter two numbers, and then computes the minimum  and 
maximum of the two numbers using the conditional operator
*******************************************************************************************/

#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{  
	//Declare variables 
	int num1; //variable for first # input
	int num2; //Variable for second # input
	int min; //Variable for minimum of two numbers
	int max; //Variable for maximum of two numbers

	cout << "********************************\n"
		<< "Please enter two numbers\n"             //Get users input
		<< "********************************\n";
	cin >> num1 >> num2;

	if (num1 > num2)
	{                                             //Case 1 statement 
		max = num1;
		min = num2; //Assign to min and max once determined 

		cout << "****************************************************\n"
			<< "The minimum of the two numbers is " << min << endl
			<< "The maximum of the two numbers is " << max << endl           //Output the report 
			<< "****************************************************\n";
	}

	if (num2 > num1)
	{                                           //Case 2 statement 
		max = num2;
		min = num1;   //Assign to min and max once determined

		cout << "****************************************************\n"
			<< "The minimum of the two numbers is " << min<< endl
			<< "The maximum of the two numbers is " << max << endl                 //Output the report 
			<< "****************************************************\n";
	}


    return 0;

}