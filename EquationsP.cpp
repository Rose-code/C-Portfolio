/***************************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
5 January 2019
Equations Program
This program computes equations that calculate the volume of a cylinder, sphere, cone,
the surface area of a cone. It also calculates the height of a building and the distance
from the top of the building to the end point shadow. 
*****************************************************************************************/

#include <iostream>
#include <iomanip>  //Needed for decimal precision
#include <cmath> //Needed for sqrt and pow
using namespace std;

int main()
{
	//Declare variables
	const double pi = 3.14159;
	double volumeCyl; //Variable for volume of cylinder 
	double volumeS; //Variable for volume of a sphere 
	double volumeCo; //Variable for volume of a cone 
	double heightCyl; //Variable for height of cylinder
	double radiusCyl; //Variable for radius of cylinder 
	double radiusS; //Variable for radius of sphere 
	double heightCo; //Variable for height of cone
	double radiusCo; //Variable for radius of cone
	double sArea; // Variable for surface area of a cone
	double heightS; //Variable for height of surface area cone
	double raidusS; //Variable for radius of surface area cone
	double heightBuild; //Variable for height of building
	double shadow; //Variable for shadow casting on building
	double sun; //Variable for angle sun is at
	double distance; //Variable for distance from top of building to end point shadow

	heightCyl = 22.0;
	radiusCyl = 10.0;
	radiusS = 60.0;     //Assign values to variables 
	heightCo = 60.0;
	radiusCo = 25.0;
	heightS = 60.0;
	radiusS = 25.0;
	shadow = 330.0;

	//volumeCyl = pi * (10.0 * 10.0) * 22.0;
	volumeCyl = pi * pow(radiusCyl, 2.0) * heightCyl;
	volumeS = ((4.0 / 3.0) * pi * (pow(radiusS, 3.0)));
	volumeCo = pi * (pow(radiusCo, 2.0)) * heightS / 3.0;
	sArea = pi * radiusS * (radiusS + (sqrt(pow(heightS, 2.0) + pow(radiusS, 2.0))));

	
	
	
	
	
	cout << setprecision(2) << fixed << showpoint << endl
   << "The volume of the cylinder is " << volumeCyl << endl
	<< "The volume of the sphere is " << volumeS << endl
	<< "The volume of the cone is " << volumeCo << endl
	<< "The surface area of the cone is " << sArea << endl;







	return 0;

}