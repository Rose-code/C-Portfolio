/*********************************************************************************
Morgan Hughes
CS 318
Dr. Brady Rimes
6 September 2019
2D Array Program
This program manipulates a 2d array and solves a finite amount of problems with
a select set of funtions. 
***********************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;


ifstream infile;
ofstream outfile;

//Prototypes
int** read_file_td_arr();
void print_arr(int **arr);
int getRowTotal(int **arr, int row);
int getColTotal(int **arr, int col);
int GetLowestInRow(int **arr, int row);
int GetLowestInCol(int **arr, int col);
int GetHighestInRow(int **arr, int row);
int GetHighestInCol(int **arr, int col);
// void LineFormat(int **arr, int length);


int main()
{

	//Open files
	infile.open("TwoDim.txt");
	outfile.open("2DaryReport.txt");

	int **arr;
	int length;
	outfile << "******ARRAY******\n";
	arr = read_file_td_arr();
	//LineFormat(**arr, length);
	print_arr(arr);

	//Declare variables
	double avg;
	int sum = 0;
	
	for (int i = 0; i < 15; i++)
	{
		sum += getRowTotal(arr, i);

	}

	avg = (double)sum / (15.0 * 15.0);

	outfile << "***************************************\n"
		    << "The average = " << avg << endl;

	sum = 0; //Reset sum value to 0 each time 9prime the loop)
	for (int i = 5; i < 11; i++)
	{
		sum = getRowTotal(arr, i);

		outfile << "***************************************\n"
			    << "The total of rows 5 - 10: " << i << " is: " << sum << endl;
	}

	for (int i = 1; i < 14; i = i + 2)
	{

		outfile << "***************************************\n"
			    << "The highest in odd row: " << i << " is: " << GetHighestInRow(arr, i) << endl;
	}

	sum = 0;
	for (int i = 2; i < 9; i++)
	{
		sum += getColTotal(arr, i);
	}

	outfile << "***************************************\n"
		    << "The sum of all values from Col 2-8 is: " << sum << endl;

	sum = 0;
	for (int i = 0; i < 15; i++)
	{
		sum += getRowTotal(arr, i);
	}

	outfile << "***************************************\n"
		    << "The sum of all values from row 10-14 is: " << sum << endl;

	sum = 0;
	for (int i = 2; i < 9; i++)
	{
		sum += GetHighestInCol(arr, i);
	}

	outfile << "***************************************\n"
	      	<< "The sum of all biggest values in col 2-8 is: " << sum << endl;

	sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum += GetLowestInRow(arr, i);
	}

	outfile << "***************************************\n"
		    << "The sum of all the smallest values in row 0-6 is: " << sum << endl
		    << "***************************************\n";

	//Close files
	infile.close();
	outfile.close();

	//Terminate program
	return 0;
}

int** read_file_td_arr()  //Read in array
{
	ifstream in("TwoDim.txt");
	int** arr = 0;
	int temp;
	int loop_stop = 0;

	arr = new int*[15];
	
	for (int i = 0; i < 15; i++)
	{
		arr[i] = new int[15];

		for (int j = 0; j < 15; j++)
		{
           if (in >> temp)
			arr[i][j] = temp;
            else
		    {
			loop_stop = 1;
			break;
		    }

		}
		
		if (loop_stop == 1)
		break;
	}
	in.close();

	return arr;
}

void print_arr(int **arr)   //Print array
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			outfile << arr[i][j] << " ";
			
		}
		outfile << endl << endl;
	}
}

int getRowTotal(int **arr, int row)  
{
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		sum += arr[row][i];

	}
	return sum;
}

int getColTotal(int **arr, int col)  
{
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		sum += arr[i][col];
	}

	return sum;
}

int GetLowestInRow(int **arr, int row)
{
	int min = arr[row][10];
	for (int i = 1; i < 15; i++)
	{
		if (arr[row][i] < min)
			min = arr[row][i];
	}

	return min;
}

int GetLowestInCol(int **arr, int col)
{
	int min = arr[0][col];
	for (int i = 1; i < 15; i++)
	{
		if (arr[i][col] < min)
			min = arr[i][col];
	}
	return min;
}

int GetHighestInRow(int **arr, int row)
{
	int max = arr[row][0];
	for (int i = 1; i < 15; i++)
	{
		if (arr[row][i] > max)
			max = arr[row][i];
	}

	return max;
}

int GetHighestInCol(int **arr, int col)
{
	int max = arr[0][col];
	for (int i = 1; i < 15; i++)
	{
		if (arr[i][col] > max)
			max = arr[i][col];
	}

	return max;
}

