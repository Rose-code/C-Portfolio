/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
3 February 2019
Grapevines Program
***********************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int length; //Variable for the length of rows of grapevines
	int trellis; //Variable for amount of space used by end-post trellis
	int space; //Variable for amount of space in between the vines
	int grapevines; //Variable for # of grapevines to be calculated per row

	cout << "********************************************\n"
		<< "Please enter the length of the row in feet\n"            //Get the input length 
		<< "********************************************\n";
	cin >> length;

	cout << "******************************************************\n"
		<< "Please enter the amount of space of the trellis in feet\n"      //Get the input trellis space
		<< "******************************************************\n";
	cin >> trellis;

	cout << "******************************************************\n"
		<< "Please enter the amount of space between the vines in feet\n"      //Get the input space between the vines
		<< "******************************************************\n";
	cin >> space;

	grapevines = (length - (2 * trellis)) / space;  //Formula to calculate how many grapevines will fit

	cout << "************************************************************\n"
		<< "The number of grapevines that will fit in a row is " << grapevines << endl   //Display the report
		<< "************************************************************\n";

	return 0;





}