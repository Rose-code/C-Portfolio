/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
24 January 2019
Area of a Cone Program
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	double area;
	const double pi = 3.14159;
	double height;
	double radius;
	double Lslant;

	cout << "***********************************\n"
		<< "Please enter the height of the cone\n"
		<< "***********************************\n";
	cin >> height;

	cout << "***********************************\n"
		<< "Please enter the radius of the cone\n"
		<< "***********************************\n";
	cin >> radius;

	Lslant = height pow(2.0) + radius pow(2.0);

	cout << "***************************************\n"
		<< "The area of the cone is " << area << endl
		<< "***************************************\n";

	return 0;



}