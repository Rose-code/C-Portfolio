/*********************************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
9 January 2020
Monthly Payments Program
This program calculates the monthly payments on a given loan and writes a report to
an outfile with listed specs.
***********************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

ofstream outFile;


int main()
{
	//Declare variables
    int loanLength, amountOfPayments;
    float loanAmount, yearInterest, monthInterest, monthlyPayment, paidBack, interestPaid;

	//Open file
	outFile.open("PaymentsReport.txt");

	//Get user input
	outFile << "*********************************\n"
		    << "How much is your loan?\n"
		    << "*********************************\n";

	cout  << "*********************************\n"
		 << "How much is your loan?\n"
		 << "*********************************\n";

	cin >> loanAmount;
	outFile << loanAmount << endl;

	outFile << "*********************************\n"
		    << "What is your annual interest rate?\n"
		    << "*********************************\n";

	cout << "*********************************\n"
		 << "What is your annual interest rate?\n"
		 << "*********************************\n";

	cin >> yearInterest;
	outFile << yearInterest << endl;

	outFile << "*********************************\n"
		<< "How many years will your loan last?\n"
		<< "*********************************\n";

	cout << "*********************************\n"
		<< "How many years will your loan last?\n"
		<< "*********************************\n";

	cin >> loanLength;

	outFile << loanLength << endl << endl << endl << endl;

	//Formulas needed for calculations
	amountOfPayments = loanLength * 12;

	monthInterest = (yearInterest / 12) / 100;

	monthlyPayment = ((monthInterest * pow(1 + monthInterest, amountOfPayments)) / (pow(1 + monthInterest, amountOfPayments) - 1)) * loanAmount;

	paidBack = monthlyPayment * amountOfPayments;

	interestPaid = paidBack - loanAmount;

	//Write report to file
	outFile << setprecision(2) << fixed;
	outFile << "***********************************************************************\n";
	outFile << "Loan Amount:" << setw(13) << "$ " << loanAmount << endl;
	outFile << "Monthly Interest Rate:" << setw(3) << "% "<< monthInterest * 100 << endl;
	outFile << "Number of Payments:" << setw(6) << "  " << amountOfPayments << endl;
	outFile << "Monthly Payments:" << setw(8) << "$ " << monthlyPayment << endl;
	outFile << "Amount Paid Back:" << setw(8) << "$ " << paidBack << endl;
	outFile << "Interest Paid:" << setw(11) << "$ " << interestPaid << endl;
	outFile << "***********************************************************************\n";

	//Close file
	outFile.close();

	//Terminate program
	return 0;
}


