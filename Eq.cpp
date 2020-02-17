/*****************************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
5 January 2019
Equations Program
This program computes equations that calculate the volume of a cylinder, sphere, cone,
and the surface area of a cone. It also calculates the height of a building and the distance
from the top of the building to the end point shadow.
*******************************************************************************************/

#include <iostream>
#include <iomanip>  //Needed for decimal precision
#include <cmath> //Needed for sqrt and pow
using namespace std;

int main()
{
	//Declare variables
	const double pi = 3.14159; //Constant variable of pi
	double volumeCyl; //Variable for volume of cylinder 
	double volumeS; //Variable for volume of a sphere 
	double volumeCo; //Variable for volume of a cone 
	double sArea; // Variable for surface area of a cone
	double b; //Variable for height of building
	double h; //Variable for hypotenuse 
	double angle; //Variable for angle of sun

	angle = 75; //must convert this to radians 


	volumeCyl = pi * (10.0 * 10.0) * 22.0;
	volumeS = 4.0 * (pi * pow(60.0, 3.0)) / 3.0;
	volumeCo = pi * (25.0 * 25.0) * (60 / 3);
	sArea = pi * 25.0 * (25.0 + (sqrt(60.0 * 60.0 + 25.0 * 25.0)));

	
	//cos(75) = 330 / h and sin(75) = b / h and tan(75) = b / 330;
	//convert this to radians here
	angle = angle * (pi / 180);

	b = 330 * tan(angle); //Calculate the height of the building 

	h = 330 / cos(angle); //Calculate the hypotenuse 


   cout << setprecision(2) << fixed << showpoint << endl
		<< "****************************************************************************\n"
		<< "The volume of the cylinder = " << volumeCyl << endl
		<< "The volume of the sphere = " << volumeS << endl
		<< "The volume of the cone = " << volumeCo << endl
		<< "The surface area of the cone = " << sArea << endl
		<< "The height of the building = " << b << " feet" << endl
		<< "The distance from the top of the building to the end point = " << h << " feet" << endl
		<< "****************************************************************************\n";
	    

	  return 0;

}