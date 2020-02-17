/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
20 March 2019
Falling Distance Program
This program computes the distance an object will fall, traveling down for 1 
seconds to 15 seconds 
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outfile;

//Prototypes
double fallingDistance(int time); //Function to calculate and return falling distance 
void printHeader(); //Function to print out header to file
void printReport(int time, double distance);  //Function to print report 

int main()
{
	outfile.open("FallingReport.txt"); //Open outfile

	//Call function to print header in table format
	printHeader();
	for (int i = 1; i <= 15; i++) //For loop to calculate and call functions 
	{
		
		printReport(i, fallingDistance (i)); //Call printReport function and send to outfile

		
	}

	outfile.close();  //Close file 
	
	return 0;
}

//Function that calculates and returns falling distance 
double fallingDistance(int time)  
{
	return 0.5 * 9.8 * time * time;
}

//Function that prints header of report to a file 
void printHeader()
{
	outfile << "**TIME** \t\t **DISTANCE**"  << endl;
}

//Function that prints report to file
void printReport(int time, double distance)
{
	outfile << time << "\t\t\t" << distance << endl;
}