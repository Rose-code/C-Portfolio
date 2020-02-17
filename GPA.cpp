/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
16 February 2019
GPA Program
This program calculates the grade point of each class as well as the GPA of all
courses taken,and then displays a report for the student 
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Declare Variables
	string firstName; //Variable for string of first name user input
	string lastName; //Variable for last name of user input 
	double g1; //Variable for grade 1
	double g2; //Variable for grade 2
	double g3; //Variable for grade 3
	double g4; //Variabe for grade 4
	double c1; //Variable for class 1
	double c2; //Variable for class 2
	double c3; //Variable for class 3
	double c4; //Variable for class 4 
	double Gp1; //Variable for grade point of class one 
	double Gp2; //Variable for grade point of class two 
	double Gp3; //Variable for grade point of class three
	double Gp4; //Variable for grade point of class four
	double avg; //Variable for average of all course GP's



	//Get user input 
	cout << "********************************************************************************************************\n"
		<< "Please enter your first and last name, followed by your paired credit hour and grades\n"
		<< "*********************************************************************************************************\n";
	cin >> firstName >> lastName >> c1 >> g1 >> c2 >> g2 >> c3 >> g3 >> c4 >> g4;

	
	
	if (g1 || g2 || g3 || g4 >= 90)
	{
		Gp1 = 4.0;
		Gp2 = 4.0;
		Gp3 = 4.0;
		Gp4 = 4.0;
	}

	if (g1 || g2 ||  g3 ||  g4 < 90 && g1 || g2 || g3 || g4 >= 80)
	{
		Gp1 = 3.0;
		Gp2 = 3.0;
		Gp3 = 3.0;
		Gp4 = 3.0;
	}

	if (g1 || g2 || g3 || g4 < 80 && g1 ||  g2 ||  g3 || g4 >= 70)
	{
		Gp1 = 2.0;
		Gp2 = 2.0;
		Gp3 = 2.0;
		Gp4 = 2.0;
	}

	if (g1 ||  g2 ||  g3 || g4 < 70 && g1 || g2 || g3 || g4 >= 60)
	{
		Gp1 = 1.0;
		Gp2 = 1.0;
		Gp3 = 1.0;
		Gp4 = 1.0;
	}

	if (g1, g2, g3, g4 < 60)
	{
		Gp1 = 0.0;
		Gp2 = 0.0;
		Gp3 = 0.0;
		Gp4 = 0.0;
	}

	avg = Gp1 + Gp2 + Gp3 + Gp4 / 4;


	cout <<"****************************************************************************************\n"
		<< lastName << ", " << firstName << " " << Gp1 << "-" << c1 << " " << Gp2 << "-" << c2 << " " << Gp3 << "-" << c3 << " " << c4 << "-" << Gp4 << avg << endl
	<< "****************************************************************************************\n";

	return 0;




}