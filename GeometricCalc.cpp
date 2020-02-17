/*********************************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
22 May 2019
Geometric Calculator Program
This program displays a menu to calculate the area of a circle, rectangle, or 
triangle. It then sends the report to a file. 
***********************************************************************************/

//Header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

ofstream outfile;

int CalcChoice(); //function for choice 
void CalcSwitch(int); //Switch statement 

//Declare Variables
const int CIRCLECALC = 1;
const int RECTANGLECALC = 2;   //Choices 1-4
const int TRIANGLECALC = 3;
const int QUIT = 4;
const float PI = 3.14159;
int choice;
double area;


int main()
{
	outfile.open("GeometryResultReport.txt");  //Open file

	CalcChoice(); //Call function

	CalcSwitch(choice); //Call switch statement 

	outfile.close(); //Close file

	return 0;
}

int CalcChoice()
{
	outfile << "**********************************\n";
	outfile << "Geometry Calculator" << endl;
	outfile << "1. Calculate the Area of a Circle" << endl;
	outfile << "2. Calculate the Area of a Rectangle" << endl;
	outfile << "3. Calculate the Area of a Triangle" << endl;
	outfile << "4. Quit" << endl;
	outfile << "Enter your choice (1-4): ";
	outfile << "**********************************\n";

	cout << "**********************************\n";
	cout << "Geometry Calculator" << endl;
	cout << "1. Calculate the Area of a Circle" << endl;
	cout << "2. Calculate the Area of a Rectangle" << endl;
	cout << "3. Calculate the Area of a Triangle" << endl;
	cout << "4. Quit" << endl;
	cout << "**********************************\n";
	cout << "Enter your choice (1-4): ";

	cin >> choice;

	outfile << choice << endl << endl;

	return choice;
}

void CalcSwitch(int choice)
{
	//Declare local variables needed for switch statement 
	int radius, length, width, base, height;

	switch (choice)
	{
	case CIRCLECALC: //Case to calculate circle area

		outfile << "What is the radius? ";

		cout << "What is the radius? ";

		cin >> radius;

		if (radius < 0) //Input validation
		{
			outfile << "This program does not accept negative values!" << endl;
			return;
		}
		outfile << radius << endl;

		area = PI * pow(radius, 2); //Formula for area

		outfile << "The area of your circle is " << area << "." << endl; //Send calculation to file

		break;

	case RECTANGLECALC: //Case to calculate rectangle area

		outfile << "What is the length? ";

		cout << "What is the length? ";

		cin >> length;
		if (length < 0) //Input validation 
		{
			outfile << "This program does not accept negative values!" << endl;
			return;
		}
		outfile << length << endl;

		outfile << "What is the width? ";
		cout << "What is the width? ";
		cin >> width;
		if (width < 0)
		{
			outfile << "This program does not accept negative values!" << endl;
			return;
		}
		outfile << width << endl;

		area = length * width;

		outfile << "The area of your rectangle is " << area << "." << endl; //Send calculation to file

		break;

	case TRIANGLECALC: //Choice to calculate triangle area

		outfile << "What is the base? ";

		cout << "What is the base? ";

		cin >> base;
		if (base < 0)   //Input validation
		{
			outfile << "The program does not accept negative values!" << endl;
			return;
		}
		outfile << base << endl;

		outfile << "What is the height? ";
		cout << "What is the height? ";
		cin >> height;
		if (height < 0)
		{
			outfile << "The program does not accept negative values!" << endl;
			return;
		}
		outfile << height << endl;

		area = base * height * 0.5; //formula for area

		outfile << "The area of your triangle is " << area << "." << endl;  //Send calculation to file

		break;

	case QUIT: //choice 4 (to quit)

		outfile << "Program has ended!" << endl;

		break;

	default:

		outfile << "The valid choices are 1-4!" << endl;  //Default statements in case of invalid chocies
		outfile << "Please try again!";

		break;
	}
}
