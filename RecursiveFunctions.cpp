/***********************************************************************
Morgan Hughes 
CS 318 
Dr. Brady Rimes 
Recursive functions 
This program uses several different recursive functions to compute a 
finite amount of solutions
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

ofstream outfile;

//Prototypes
int SumIt(int *aryptr, int numEl);
int RecursiveMult(int x, int y);
int sumOnum(int num);
int DigitCount(int number);
void PrintReverse(int num); 
void printArray(int *ary2ptr, int i);
int FindLargest(int ary2[],int i, int largest);
int FindSmallest(int ary2[], int i, int smallest);
int DigitSum(int number);
int singleDigitSum(int number);

 int ary1[9] = { 48, 54, 67, 92, 87, 75, 48, 31, 81 };
	 int ary2[9] = { 48, 54, 77, 92, 87, 85, 48, 31, 81 };


int main()
{
	//declarations
	int ary1[9];
	int ary2[9];
	 int *aryptr;
	 aryptr = &ary1[0];
	  int numEl = 9;
	  int x, y, i;
	  int num;
	  int *ary2ptr;
	  ary2ptr = &ary2[0];
	  int number;
	  int max, min;

	  //outfile
	  outfile.open("RecursionReport.txt");


	 //Call functions


	 //Summing elements in array (#4 in book)
	  
	 outfile << "**************************\n"
		 << "The sum of the array is: " << SumIt(aryptr, numEl);


       //recursive multiplication (#5 in book)
       cout << "Please enter two numbers to be multiplied\n";

		cin >> x >> y;

	 outfile << "**************************\n"
		 << "X * Y = " << RecursiveMult(x, y);


	//Sum of numbers (#7 in book)

	 cout << "Please enter numbers to be (+)\n";

	 cin >> num;

	 outfile << "**************************\n"
		 << "The sum of numbers is: " << sumOnum(num);

	 //Digit count
     cout << "Please enter a number to count the digits\n";
	
	cin >> number;

	 outfile << "**************************\n"
		 << "The digit count of the number is: " << DigitCount(number);


	 //Print number in reverse 
     cout << "Please enter a number to be reversed\n";

	cin >> num;

	 PrintReverse(num);

	 //print array forwards and then backwards 
	 printArray(ary2ptr, i);

	 //finding max in array
	 outfile << "**************************\n"
		 << "The largest number in the array is: " << FindLargest(ary2, i, max);


	 //finding min in array
	 outfile << "**************************\n"
		 << "The smallest number in the array is: " << FindSmallest(ary2, i, min);

	 //Sum of the digits
     cout << "Please enter a number for digits to be (+)\n";
	
	cin >> x;

	 outfile << "**************************\n"
		 << "The sum of digits in the # entered is: " << DigitSum(x);

     //single digit sum
     cout << "Please enter a number for single digit (+)\n";

	cin >> num;

	 
	 outfile << "**************************\n"
		 << "The single digit sum of the # entered is: " << singleDigitSum(num);

	 //close files
	 outfile.close();

	 return 0; //terminate program
}

//Recursive function to sum elements in array (#4 in book)
int SumIt(int *aryptr, int numEl)
{
	//numEl = 9;

	//base case
	if (numEl == 0)
	{
		return 0;
	}
	else 

	 return *aryptr + SumIt(aryptr + 1, numEl - 1);
}
//Recursive multiplication function (#5 in book)
int RecursiveMult(int x, int y)
{
	

		if (x == 0 || y == 0)
		{
			return 0;
		}

		else 
			return y + RecursiveMult(x - 1, y);

}
//Recursive sum of numbers function (#7 in book)
int sumOnum(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	     
		return num + sumOnum(num - 1);
	
}
//Recursive function to count digits in any number 
int DigitCount(int number)
{
	if (number == 0)
	{
		return 0;
	}
	else
	{
		return 1 + DigitCount(number / 10);
	}
}
//Recursive function to print number out in reverse order
void PrintReverse(int num)
{
	
	//base case 
	if (num == 0)
	{
		return;
	}

	//open report file
	outfile.open("RecursionReport.txt");

	outfile <<"**************************\n"
		<< "Number printed in reverse: "
		<< num % 10 << " \n";

	PrintReverse(num / 10);
}
//Recursive function to print values in array out frontwards and backwards 
void printArray(int *ary2ptr, int i)
{
	if (i == 0)
	{
		return;
	}

	outfile.open("RecursionReport.txt");

	outfile << "The array forwards is: " << *ary2ptr << " ";

	printArray(++ary2ptr, i--);

	outfile << "The array backwards is: " << *ary2ptr << " ";
}
//Recursive function to find the largest value in an array
int FindLargest(int ary2[], int i, int largest)
{

	if (largest == 0)
	{
		return 0;
	}

	else
		if (ary2[i] > largest)
		{
			largest = ary2[i];
		}
		return FindLargest(ary2, i--, largest);
}
//Recursive function to find the smallest value in an array
int FindSmallest(int ary2[], int i, int smallest)
{

	if (smallest == 0)
	{
		return 0;
	}

	else
		if (ary2[i] < smallest)
		{
			smallest = ary2[i];
		}
	return FindLargest(ary2, i--, smallest);
}
//Recursive function that computes sum of digits for a given positive int argument
int DigitSum(int number)
{
	

	if (number == 0)
	{
		return 0;
	}
	else
	{
		return (number % 10) + DigitSum(number / 10);
	}
}
//Recursive function to compute single digit sum 
int singleDigitSum(int number)
{
	
	if (DigitSum(number) == 0)
	{
		return 0;
	}
	else
	{
		return (DigitSum(number) % 10) + (DigitSum(number) / 10);
	}
}