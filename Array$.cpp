/**************************************************************************
Morgan Hughes
16 January 2020
CS 318
Dr. Brady Rimes
This program manipulates an array and reports a finite set of functions.
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

ofstream outfile;
ifstream infile;
ifstream infile2;

//Prototypes
int Readin(int[], int); //to read vals into array
int getSize(int[]); //to calculate size of array
void Print(int); //to print array elements
float Avg(int[], int); //to sum vals for avg calculations 
int Larger(int[], float, int); //to find larger vals than avg
int Smaller(int[], float, int); //to find smaller vals than avg
int convert(int[], int); //change array to all (+)
int FindL(int[], int); //find largest val
int Lspot(int[], int); //find position of largest val
int FindS(int[], int); //find largest val
int Sspot(int[], int);  //find position of largest val
int ZeroOut(int[], int); //convert all even nums to zeros
int lessThanInput(int[], int, int); //to find which nums in array are < input file param 1
int greaterThanInput(int[], int, int); //to find which nums in array are > input file param 2
int greaterElements(int[], int, int); //find elements > param3
int Multiples(int[], int, int, int); //find which elements are multiples of 4 and 5 input data
int Copy(int[], int, int[]); //copying all elements from first array to 2nd
void printArray2(int[], int); //print routine for ary2
int Reverse(int[], int[], int); //reverse elements of ary2[]
void printReverse(int[], int); //print routine for reversed array

//declare arrays
     int ary[100];
	 int ary2[100];

int main()
{
	

	//open files
	infile.open("array.txt");
	outfile.open("ArrayReport.txt");
	infile2.open("AryParams.dat");

	//declare variables
	const int count = 100;
	float avg;
	int subs = 0;
	int counter;
	int larger;
	int smaller;
	int position;
	int largest;
	int smallest;
	int param1;
	int param2;
	int param3;
	int param4;
	int param5;
	int multiples;
    
	outfile << "ARRAY REPORT\n"
		<< "***************************\n";

	// 1) read variables into array
	Readin(ary, subs);

	// 2) print array
	counter = getSize(ary); //call function that determines size of array to use in print routine
	Print(counter);

	// 3)  avg array
	avg = Avg(ary, counter);
	outfile << "The average of the array is: " << avg << endl
		<< "***************************\n";

	// 4) Print out values larger and smaller than avg
	larger = Larger(ary, avg, counter);
	outfile << "There are " << larger << " numbers in the array larger than the avg\n"
		<< "***************************\n";

	smaller = Smaller(ary, avg, counter);
	outfile << "There are " << smaller << " numbers in the array smaller than the avg\n"
		<< "***************************\n";
	//5) convert array to all (+) and find new avg
	convert(ary, counter);

	outfile << "The new array is: \n";

	Print(counter);

	outfile << "***************************\n";

	//6) print avg of new array
	avg = Avg(ary, counter);
	outfile << "The average of the new array is: " << avg << endl
		<< "***************************\n";

	// 7-8) find largest val in new array and its position
	largest = FindL(ary, counter);
	position = Lspot(ary, counter);

	outfile << "The largest val in the array is: " << largest << endl
		<< "Its position: " << position << endl
		<< "***************************\n";

	smallest = FindS(ary, counter);
	position = Sspot(ary, counter);

	outfile << "The smallest val in the array is: " << smallest << endl
		<< "Its position: " << position << endl
		<< "***************************\n";

	// 9) Zero out all even numbers in the array and print the new array
	ZeroOut(ary, counter);

	outfile << "The new array is: \n";
		Print(counter);
	outfile	<< "***************************\n";

	// 10) print avg of new array
	avg = Avg(ary, counter);
	outfile << "The average of the new array is: " << avg << endl
		<< "***************************\n";
	
	// 11) How many vals in array above are less than input #1 infile2
	infile2 >> param1;

	smaller = lessThanInput(ary, counter, param1); 

	outfile << "The num of vals in the array < than " << param1 << " are " << smaller <<  endl
		<< "***************************\n";

	// 12) How many vals in array above are greater than input #2 infile2
	infile2 >> param2;

	larger = greaterThanInput(ary, counter, param2);

	outfile << "The num of vals in the array > than " << param2 << " are " << larger << endl
		<< "***************************\n";

	// 13) How many nums are greater than ary[3rd#] in array
	infile2 >> param3;

	larger = greaterElements(ary, counter, param3);

	outfile << "The num of vals in the array > than " << param3 << " are " << larger << endl
		<< "***************************\n";

	// 14) how many elements are multiples of param4 and param5
	infile2 >> param4;
	infile2 >> param5;

	multiples = Multiples(ary, counter, param4, param5);

	outfile << "The num of vals in the array that are multiples of " << param4  << " & " <<  param5 <<  " are " << multiples << endl
		<< "***************************\n";

	// 15) copying elements from first array to 2nd array
	Copy(ary, counter, ary2);

	outfile << "The new array is: \n";
	printArray2(ary2, counter);
	outfile << "***************************\n";

	// 16) reversing elements from 2nd array
	Reverse(ary, ary2, counter);

	outfile << "The new array is: \n";
	printReverse(ary2, counter);
	outfile << "\n***************************\n";


	return 0; //terminate program

}

int Readin(int ary[], int vals)
{
	int i = 0;
	
	while (infile >> vals)
	{
	   ary[i] = vals;
		i++;
	}

	return ary[i];
}

int getSize(int ary[])
{
	int i = 0;
	while(ary[i] != 0)
	{
		i++;
	}

	return i;
}

void Print(int counter)
{
	for (int i = 0; i < counter; i++)
	{
		outfile << ary[i] << " " ;

		if ((i + 1) % 10 == 0)
			outfile << endl;
	}

	return;
}

float Avg(int ary[], int len)
{
	float sum = 0;
	float avg;


	for (int i = 0; i < 100; i++)
	{
		sum = sum + ary[i];
	}

	avg = (float) sum / len;

	return avg;
	
}

int Larger(int ary1[], float avg, int counter)
{
	int larger = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary1[i] > avg)
		{
			larger++;
		}
		
	}

	return larger;
}

int Smaller(int ary[], float avg, int counter)
{
	int smaller = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] < avg)
		{
			smaller++;
		}
		
	}

	return smaller;

}

int convert(int ary[], int counter)
{
	int i;
	for ( i = 0; i < counter; i++)
	{
		if (ary[i] < 0)
		{
			ary[i] = ary[i] * -1;
		}
	}

	return ary[i];
}

int FindL(int ary[], int counter)
{
	int largest = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] > largest)
		{
			largest = ary[i];
		}
		
	}

	return largest;
}

int Lspot(int ary[], int counter)
{
	int largest = 0;
	int spot = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] > largest)
		{
			largest = ary[i];
			spot = i;
		}
	}

	return spot;
}

int FindS(int ary[], int counter)
{
	int smallest = ary[0];
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] < smallest)
		{
			smallest = ary[i];
		}

	}

	return smallest;
}

int Sspot(int ary[], int counter)
{
	int smallest = ary[0];
	int spot = ary[0];
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] < smallest)
		{
			smallest = ary[i];
			spot = i;
		}
	}

	return spot;
}

int ZeroOut(int ary[], int counter)
{
	int i;
	for (i = 0; i < counter; i++)
	{
		if (ary[i] % 2 == 0)
		{
			ary[i] = 0;
		}
	}

	return ary[i];
}

int lessThanInput(int ary[], int counter, int param1)
{
	int smaller = ary[0];
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] < param1)
		{
			smaller++;
		}
	}

	return smaller;
}

int greaterThanInput(int ary[], int counter, int param2)
{
	int larger = ary[0];
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] < param2)
		{
			larger++;
		}
	}

	return larger;
}

int greaterElements(int ary[], int param3, int counter)
{
	int gE = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] > param3)
			gE++;
	}

	return gE;
}

int Multiples(int ary[], int param4, int counter, int param5)
{
	int multiples = 0;
	for (int i = 0; i < counter; i++)
	{
		if (ary[i] % param4 == 0 && ary[i] % 5 == 0)
		{
			multiples++;
		}
	}

	return multiples;
}

int Copy(int ary[], int counter, int ary2[])
{
	int i;
	for ( i = 0; i < counter; i++)
	{
		ary2[i] = ary[i];
	}

	return ary2[i];
}

void printArray2(int ary2[], int counter)
{
	int i;
	for (i = 0; i < counter; i++)
	{
		outfile << ary2[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			outfile << endl;
		}
	}
        	return;
}

int Reverse(int ary[], int ary2[], int counter)
{
	int i;
	for (i = counter; i > 0; i--)
	{
		ary2[i] = ary[i];
	}
	return ary2[i];
}

void printReverse(int ary2[], int counter)
{
	int i;
	for (i = counter -1; i >= 0; i--)
	{
		outfile << ary2[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			outfile << endl;
		}
	}
	return;
}