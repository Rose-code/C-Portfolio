/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
27 March 2019
Lumber Order Program
This program computes the cost of a lumber order for a local lumber company. 
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

ifstream infile;
ofstream outfile;

//Prototypes
double typeCost(char type);
void readCustomer(ifstream& infile, ofstream& outfile);
double BoardFeet(double width, double height, double feet);
double Cost(double boardF, double typeCost);
void PrintHeader(ofstream& outfile, string customerID);
void printRow(int count, int W, int H, int L, double cost, char type);
void printSum(double sum);

int main()
{
	//Open files
	infile.open("LumberOrder.txt");
	outfile.open("LumberReport.txt");

	//Verify file opened properly
	if (!infile.good())
	{
		cout << "File did not open correctly\n";
	}


	while (infile) //while loop for infile
	{
	
		readCustomer(infile, outfile);

	}


	infile.close();   //Close files
	outfile.close();

	return 0;


}

double typeCost(char type)
{
	switch (type)
	{
		case 'P': 1.05;
			break;
		case 'F': 1.29;
			break;
		case 'C': 2.25;
			break;
		case 'M': 4.10;
			break;
		case 'O': 2.40;
			break;

	}

	return type;
}

void readCustomer(ifstream& infile, ofstream& outfile)
{
	
	//Declare variables 
	char readChar;
	string data;
	string temp;
	string customerID;
	double sum;
	sum = 0;
	
	infile >> temp;
	infile >> temp;
	infile >> customerID;
	infile >> readChar;
	if (!infile) {
		return;
	}
    PrintHeader( outfile, customerID);
	
	while (infile && readChar != 'T')
	{
		char type;
		double count;
		double W;
		double H;
		double L;
		double cost;

		type = readChar;
		infile >> count;
		infile >> W;
		infile >> H;
		infile >> L;
		infile >> readChar;
		cost = Cost(BoardFeet(W, H, L),typeCost(type));
		sum += cost;
		printRow( count, W, H, L, cost, type);
	}
	
	printSum(sum);
}   


double BoardFeet(double width, double height, double length)
{
	double boardF;
	double squareft;

	squareft = (length * width) / 12; 
	boardF = squareft * height;

	return boardF;
}

double Cost(double boardF, double typeCost)
{
	return boardF * typeCost;
	
}

void PrintHeader(ofstream& outfile, string customerID)
{
	outfile << string("Customer Order report\n ")  << string("Customer ID # ") << customerID  << string("\ncounts\tsize\twood\tcost\n");
}

void printRow(int count, int W, int H, int L, double cost, char type)
{
	outfile << left << (count) << "\t" << (W)  << setw(1) <<  "x"  << (H)  <<  "x" << (L) <<  "\t" << type << ("\t") << setprecision(2) << fixed << showpoint << (cost) << ("\n");
}

void printSum(double sum)
{
	outfile <<  "The total cost is " << setw(10) << (sum) << ("\n\n");
}