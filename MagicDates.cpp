/*****************************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
8 February 2019
Magic Dates Program
This program asks the user to enter a month, date, and year. It then computes whether
or not the date entered is magic or not magic 
*******************************************************************************************/

#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
	//Declare Variables 
	int month;  //Variable for month 
	int day;   //Variable for day
	int year; //Variable for year
	char slash; //Dummy Variable to use for /

	

	cout << "************************************\n"
		<< "Please enter a month, day, and year\n"     //Get user input of day, month, year
		<< "************************************\n";
	cin >> month >> slash >> day >> slash >> year;

	if (month * day == year)
	{
		cout << "****MAGIC DATE****\n";             //Use if statement to determine whether input is magic
	}

	else
		cout << "****NOT A MAGIC DATE****\n";   //Use else to output message of not magic

	return 0;
}