/*****************************************************************************
Morgan Hughes 
Cs 318
30 January 2020
Dr. Brady Rimes
This program runs a simulation 7000 times to calculate the average cost of a 
walk across an island for Harvey, the drunk. It also calculates the number of 
times Harvey made it across the island, and also the number of times he had to
be rescued from the water. 
********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

ofstream outfile;


//Prototypes 
void ZerOut(int Island[][14]); //fill array with zeros
void Print(int Island[][14]); //Print routine to check array elements throughout program
void FillNeg1(int Island[][14]); //Fille correct coordinates w/ (-1)
void Fill2(int Island[][14]); //Fill island w/ 2's for flowers 
void FillPath(int Island[][14]); //Fill path in ary w/ 0's
void FillEnd(int Island[][14]); //fill 2 end coordinates of array w/ 3's (end of path & beginning)
void firstStep(int Island[][14], int&, int&); //to simulate harveys first step onto island path
void WalkResult(int Island[][14], int&, int&, int&, int&, int&); //to Calculate each walks result
float avgCost(int); //to calculate avg of walk
void printStats(float, int, int, int); //to print to file harveys walk report 
void IslandWalk(int Island[][14], int&, int&, int&); //Simulation of walk across island



//Declare array
int Island[13][14];


int main()
{
	//open outfile
	outfile.open("WalkSimulation.txt");

	//declare variables
     int flowers, times, failed, passed, backToStart, row, col;
	float avg;

     flowers = 0;
	passed = 0;
	failed = 0;
	backToStart = 0;
	avg = 0.0;


	//fill ary and check
	ZerOut(Island);
	FillNeg1(Island);
	Fill2(Island);
	FillPath(Island);
	FillEnd(Island);
	Print(Island);

	//Run simulation 7000 times
	for (times = 0; times < 7000; times++)
	{
		ZerOut(Island);
		FillNeg1(Island);
		Fill2(Island);       //fill island 
		FillPath(Island);
		FillEnd(Island);

		row = 6;     //reset array coords
		col = 0;

		firstStep(Island, row, col);
		IslandWalk(Island, row, col, flowers);   //simulate walk
		WalkResult(Island, row, col, passed, failed, backToStart);
	}

	avg = avgCost(flowers); //get avg price of walk

	printStats(avg, passed, failed, backToStart);  //send report to file 



	outfile.close(); //flush out buffers

	return 0; //terminate program

}

void ZerOut(int Island[][14])
{
	for(int r = 0; r < 13; r++)
		for (int c = 0; c < 14; c++)
		{
			Island[r][c] = 0;
		}

	return;
}

void Print(int Island[][14])
{
	for (int r = 0; r < 13; r++)
	{

		for (int c = 0; c < 14; c++)
		{
			cout << setw(3) << Island[r][c] << " ";
				
		}
		cout << endl;

	}


	return;
}

void FillNeg1(int Island[][14])
{
	for(int r = 0; r < 13; r++)
		for (int c = 0; c < 14; c++)
		{
			Island[r][c] = -1;
		}
	return;
}

void Fill2(int Island[][14])
{
	for (int r = 1; r < 12; r++)
	{
		for (int c = 1; c < 13; c++)
		{
			Island[r][c] = 2;
		}
	}
	return;
}

void FillPath(int Island[][14])
{
	for (int c = 0; c < 14; c++)
	{
		Island[6][c] = 0;
	}
	return;
}

void FillEnd(int Island[][14])
{
	Island[6][0] = 3;
	Island[6][13] = 4;

	return;
}

void printStats(float avg, int passed, int failed, int backToStart)
{
	outfile << "**********HARVEY'S ISLAND WALK REPORT**********\n"
		<< "How many times Harvey successfully crossed the island: " << passed << endl
		<< "How many times Harvey failed to cross the island:  " << failed << endl
		<< "How many times Harvey went back to the starting bridge:  " << backToStart << endl
		<< setprecision(2) << fixed
		<< "Average cost per trip across the island for Harvey:  $" << avg << endl;

	return;
}

float avgCost(int flowers)
{
	float avg;

	avg = (flowers * 4.00) / 7000.0;

	return avg;
}

void WalkResult(int Island[][14], int &row, int &col, int &passed, int &failed, int &backToStart)
{
	if (Island[row][col] == -1)
	{
		failed++;
	}
	if (Island[row][col] == 4)
	{
		passed++;
	}
	if (Island[row][col] == 3)
	{
		backToStart++;
	}
	return;
}

void IslandWalk(int islandArray[13][14], int &row, int &col, int &flowers)
{
	int numb;

	while ((islandArray[row][col] < 3) && (islandArray[row][col] > -1))
	{
		numb = rand() % 100 + 1;
		if (numb <= 44)
		{
			col++;
			if ((islandArray[row][col] == 1) || (islandArray[row][col] == 2))
			{
				islandArray[row][col] = islandArray[row][col] - 1;
				flowers++;
			}
		}
		if ((numb > 44) && (numb <= 71))
		{
			row++;
			if ((islandArray[row][col] == 1) || (islandArray[row][col] == 2))
			{
				islandArray[row][col] = islandArray[row][col] - 1;
				flowers++;
			}
		}
		if ((numb > 71) && (numb <= 92))
		{
			row--;
			if ((islandArray[row][col] == 1) || (islandArray[row][col] == 2))
			{
				islandArray[row][col] = islandArray[row][col] - 1;
				flowers++;
			}
		}
		if ((numb > 92) && (numb <= 100))
		{
			col--;
			if ((islandArray[row][col] == 1) || (islandArray[row][col] == 2))
			{
				islandArray[row][col] = islandArray[row][col] - 1;
				flowers++;
			}
		}
	}
	return;
}

void firstStep(int islandArray[13][14], int &row, int &col)
{
	int numb;

	numb = rand() % 100 + 1;
	while (numb > 44)
	{
		numb = rand() % 100 + 1;
	}
	col++;
	return;
}