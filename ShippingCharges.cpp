/*****************************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
15 February 2019
Shipping Charges Program
This program calculates the shipping charges 
*******************************************************************************************/

#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
	//Declare Variables
	double weight; //Variable for weight of package
	double distance; //Variable for the distance the package is to be shipped
	double charges; //Variable for the charges for shipment
	double unit_rate; //Variable for rate in  between unit prices 



	cout << "****************************************************************************\n"
		<< "Please enter the weight of the package and the distance it is to be shipped\n"
		<< "****************************************************************************\n";
	cin >> weight >> distance;

	if (weight <= 0 || weight > 20)
	{
		cout << "****INVALID WEIGHT****\n";
		cin >> weight;
		                                                 //Input validation 
	}

	if (distance < 10 || distance > 3000)
	{
		cout << "****INVALID DISTANCE****\n";
		cin >> distance;
	}

	unit_rate = 1.10;
	
	if (weight > 2 && weight <= 6)
	{
		unit_rate = 2.20;
	}

	if (weight > 6 && weight <= 10)
	{
		unit_rate = 3.70;
	}

	if (weight > 10 && weight <= 20)
	{
		unit_rate = 4.80;
	}


	charges = unit_rate * ceil(distance / 500);

	cout << "The total charges are: $" << charges << endl;

	return 0;


}