/******************************************************************************
Morgan Hughes
15 February 2020
CS 318
Dr. Brady Rimes
Soccer Statistics
This program reads data from a file consisting of a soccer team's information
i.e. name, id, points. This program uses structs and pointers to manipulate
this information and compute a report file with: player's name, total points,
and the highest scoring player.
**********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct Player {
	string name;    //create struct for each player on team to use
	int id;
	int totalScore;
};

//Prototypes

void sortByName(Player *players, int n); //sort players list
void printPlayers(Player *players, int n); //print routine
int getHighestPlayerScore(Player *players, int n); //find oplahyer w/ highest score

ifstream infile;
ofstream outfile;

int main()
{
	Player players[12]; //declare array of structs

	infile.open("Soccer.txt"); //open files
	outfile.open("SoccerReport.txt");

	if (infile.fail())
	{
		cout << "Unable to open file\n";   //infile validation
	}

	//Declare variables
	string line;
	int total;
	int num;
	int n = 0;
	int totalPoints = 0;
	
	//loop to read in data ffrom file
	while (!infile.eof())
	{
		getline(infile, (players + n)->name); //get line of string (name)

		infile >> (players + n)->id;   //get id #
		infile.ignore();

		getline(infile, line); 

		stringstream ss(line);
		total = 0; //reset total to 0

		while (ss >> num)
		{
			total += num;   //get total of points
		}
		(players + n)->totalScore = total;
		totalPoints += total;
		n++;
	}


      //call functions

	sortByName(players, n);
	printPlayers(players, n);

	int highScoreInd = getHighestPlayerScore(players, n); //call highest scorer function

	outfile << "******************************************\n"
		<< "Total points scored by the team: " << totalPoints << endl
		<< "******************************************\n"
		<< "Highest scored person on team: " << (players + highScoreInd)->name << " : score: "   //print results 
		<< (players + highScoreInd)->totalScore << endl
		<< "******************************************\n";

	//Close files
	infile.close();
	outfile.close();


	//terminate program
	return 0;
}


void sortByName(Player *players, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((players + i)->name > (players + j)->name)
			{
				Player temp = *(players + i);                //Swap routine
				*(players + i) = *(players + j);
				*(players + j) = temp;
			}
		}
	}
}

void printPlayers(Player *players, int n)
{

	outfile << setw(20) << left << "Name" << left << setw(20) << "ID" << left << setw(20)  <<  "Total Points" << endl;

	for (int i = 0; i < n; i++)
	{
		outfile << "******************************************\n"
		<< left	<< setw(20) << (players + i)->name << left << setw(20) << (players + i)->id << left << setw(20) <<  (players + i)
			->totalScore << endl;

	}
}

int getHighestPlayerScore(Player *players, int n)
{
	int highInd = 0;

	for (int i = 0; i < n; i++)
	{
		if ((players + highInd)->totalScore < (players + i)->totalScore)
		{
			highInd = i;
		}
	}
	return highInd;
}