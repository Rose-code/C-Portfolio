/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
16 April 2019
Yummy tummy Candy Company Program
This program reads in a txt file and computes a candy report including: the total
of each type of candy produced, the total batches produced, and the average number
of pieces produced in a batch.
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ofstream outfile;
ifstream infile;



int main()
{
	//Open files
	infile.open("Yummies.txt");
	outfile.open("CandyReport.txt");

	//File open validation
	if (!infile)
	{
		cout << "File didn't open correctly\n";
	}

	//Declare variables
	int array[23];
	int count;
	int i;
	int candyType;
	int batches;
	int candies[23];
	int Batches[23];
	double average;
	int Batch;
	int total;

	count = 0;

		for (int j = 0; j < 23; j++)
		{
			candies[j] = 0;
			Batches[j] = 0;
		}

		while(infile)
		{
			infile >> candyType >> Batch;
			candies[candyType]++;
			Batches[candyType] = Batches[candyType] + Batch;
		}



	for (i = 1; i < 23; i++)
	{
		if (candies[i] != 0)
		{
			count++;
		}

		outfile << Batches[i] << endl
			<< candies[i] << endl;

		//cout << Batches[i] << endl
			//<< candies[i] << endl;

		average = Batches[i] / candies[i];

		outfile << average << endl;
	}




	//Close files
	infile.close();
	outfile.close();

	return 0;


}


