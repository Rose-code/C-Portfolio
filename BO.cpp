/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
22 January 2019
Box Office Input Program
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string movieName;
	double Atickets;
	double Ctickets;
	double Aprice;
	double Cprice;
	double revenueP;
	double boProfit;
	double netProfit;
	double amountPaid;



	cout << "************************************************\n"
		<< "What is the name of the movie to be calculated?\n"
		<< "************************************************\n";
	cin >> movieName;

	cout << "*********************************\n"
		<< "How many adult tickets were sold?\n"
		<< "*********************************\n";
	cin >> Atickets;

	cout << "*********************************\n"
		<< "How many child tickets were sold?\n"
		<< "*********************************\n";
	cin >> Ctickets;

	Aprice = 10.00;
	Cprice = 6.00;
	revenueP = .20;

	boProfit = (Aprice * Atickets) + (Cprice * Ctickets);

	netProfit = boProfit * revenueP;

	amountPaid = boProfit - netProfit;

	//cout << "***********************************************************************\n"
	//	<< "Movie Name: " << setw(10) << movieName << endl
	//	<< "Adult Tickets Sold: " << setw(10) << Atickets << endl
	//	<< "Child Tickets Sold: " << setw(10) << Ctickets << endl
	//	<< "Gross Box Office Profit: " << setw(10) << boProfit << endl
	//	<< "Net Box Office Profit: " << setw(10) << netProfit << endl
	//	<< "Amount Paid to Distributor: " << setw(10) << amountPaid << endl
	//	<< "***********************************************************************\n";

	return 0;

}