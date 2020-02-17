/*****************************************************************************************
World Series Program                                                                      /
Written by: Morgan Hughes                                                                 /
C++ Cisp 1010                                                                             /
November 15, 2018                                                                         /
This program displays a list of baseball teams, and then computes the amount of won games /
selected by the user.                                                                     /
Inputs:Team Name                                                                          /
Outputs: Teams list, times won                                                            /
******************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Function Protoype
int timesWon(string [], int, string);
int main()
{
	cout << "**********************************************************\n"
		<< "MLB Teams That Have Won The World Series At Least Once: \n"
		<< "***********************************************************\n";
	//Declare variables
	const int SIZE = 100;
	string array[SIZE];
	int i = 0;
	string line; 
	string search_team, search, team_array[150];
	int numTeams, count;
	count = 0;
	numTeams = 0;
	ifstream infile;

	//Open file and display the array
	ifstream in;
	in.open("e:/Program 6/Teams.txt");
	if (in)
	{
		while (!in.eof() )
		{
			getline(in, line);
			array[i] = line;
			cout << array[i] << endl;
			i++;
		}
		in.close();

	}
	cout << "**************************************************************************\n"
		<< "Choose a team from the list and see how many times they've won since 1903: \n"
		<< "**************************************************************************\n";
	getline(cin, search_team);   //Get users input team

	
	infile.open("e:/Program 6/WorldSeriesWinners.txt");   //Open next file and create team_array

	if (infile)
	{   
		while (!infile.eof())
		{
			
			getline(infile, line);          
			team_array[i] = line;
			i++;
			
			numTeams++;
			
		}
		

	}
       infile.close(); //Close file
	 count=timesWon(team_array, numTeams, search_team);   //Call timesWon function
	 cout << "**************************************************************************\n"
		 << "The " << search_team << " have won the World Series " << count << " times since 1903. \n"
		 << "**************************************************************************\n";

	
	return 0;
}
//Return number of wins
int timesWon(string team_array[], int numTeams, string search_team)
{
	
	int count = 0;
	for (int i = 0; i < numTeams; i++)      //Calculate times selected team won
	{
		if (team_array[i] == search_team)
			count++;
	}
	return count;
}


