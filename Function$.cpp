/********************************************************************************
Morgan Hughes 
15 January 2020
Dr. Brady Rimes
Cs 318
Function Workout Program
This program exercises the use of several function implementations to solve
a finite set of problems.
*********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

//Prototypes
float Readin(); //function to read in data
void Print(float); //function to print input data to a file
float Sum(float, float); //function to calculate the sum
float Avg(float, float); //function to calculate the avg
float Diff(float, float); //function to calculate the diff of #s
float Pow(float, float); //function to raise one # to the other
float Largest(float, float); //function to calculate largest of nums
float Smallest(float, float); //function to calculate the smallest of nums

ofstream outfile;

int main()
{
	//open file
	outfile.open("Function$Report.txt");

	outfile << "***********************************\n"
		    << "THIS IS THE FUNCTION REPORT\n"
		    << "***********************************\n";

	//declare variables
	float n1;
	float sum, avg, difference;
	float diff2, raised, raised2;
	float largest, smallest;
	float lavg, savg, sumA, suma;
	float n2;
	float n3;
	float n4;
	float n5;
	float count = 5;

	//get input
	cout << "Please enter the 5 numbers: \n"
		 << "***********************************\n";

	//Call first function for input
	n1 = Readin();
	n2 = Readin();
	n3 = Readin();
	n4 = Readin();
	n5 = Readin();

	outfile << "The numbers are: \n"
		    << "*************************\n";

	//Call 2nd function to print input;
	Print(n1);
	Print(n2);
	Print(n3);
	Print(n4);
	Print(n5);

	//call 3rd function to calculate the sum
	sum = Sum(n1, n2);
	sum = Sum(sum, n3);
	sum = Sum(sum, n4);
	sum = Sum(sum, n5);

	outfile << "The sum of the numbers is: " << sum << endl
		    << "*************************\n";

	//call 4th function to calculate the avg
	avg = Avg(sum, count);

	outfile << "The avg of the numbers is: " << avg << endl
		    << "*************************\n";

	//call the 5th function to calculate the difference
	difference = Diff(n1, n3);

	outfile << "The difference between the 1st and 3rd number is: " << difference << endl
		    << "*************************\n";

	//call function again to get diff of 2nd and 4th nums
	diff2 = Diff(n2, n4);

	outfile << "The difference between the 2nd and 4th number is: " << diff2 << endl
	      	<< "*************************\n";

	//call the 6th function to calculate the 1st # raised to the 3rd
	raised = Pow(n1, n3);

	outfile << "The 1st raised to the 3rd number is: " << raised << endl
		    << "*************************\n";

	//call function again to calc 2nd raised to 5th
	raised2 = Pow(n2, n5);

	outfile << "The 2nd raised to the 5th number is: " << raised2 << endl
		    << "*************************\n";

	//call the 7th function to find largest num
	largest = Largest(n1, n2);
	largest = Largest(largest, n3);
	largest = Largest(largest, n4);
	largest = Largest(largest, n5);

	outfile << "The largest of the 5 numbers is: " << largest << endl
		    << "*************************\n";

	//call the 8th function to find smallest num
	smallest = Smallest(n1, n2);
	smallest = Smallest(smallest, n3);
	smallest = Smallest(smallest, n4);
	smallest = Smallest(smallest, n5);

	outfile << "The smallest of the 5 numbers is: " << smallest << endl
	    	<< "*************************\n";

	//calculate avg of 4 largest nums
	sumA = Diff(sum, smallest); //get sum of nums with smallest dropped
	lavg = Avg(sumA, 4);

	outfile << "The avg of the 4 largest nums is: " << lavg << endl
		    << "*************************\n";

	//calculate avg of 4 smallest nums
	suma = Diff(sum, largest); //get sum of nums with largest dropped
	savg = Avg(suma, 4);

	outfile << "The avg of the 4 smallest nums is: " << savg << endl
		    << "*************************\n";

	//calculate the running total
	outfile << "The running total of the number is: "
		    << n1 << " ";

	sum = Sum(n1, n2);

	outfile << sum << " ";
	                           //calculate running total by summing previous sum with next num
	sum = Sum(sum, n3);

	outfile << sum << " ";

	sum = Sum(sum, n4);

	outfile << sum << " ";

	sum = Sum(sum, n5);

	outfile << sum << " " << endl

		    << "*************************\n";


	outfile.close(); //flush the buffers


	return 0; //terminate program



}

float Readin()
{
	float num;

	cin >> num;

	return num;
}

void Print(float num)
{
	outfile << num << endl;
}

float Sum(float num1, float num2)
{
	float sum;

	return sum = num1 + num2;
}

float Avg(float sum, float count)
{
	float avg = sum / count;

	return avg;
}

float Diff(float n1, float n2)
{
	float diff = n1 - n2;

	return diff;
}

float Pow(float a, float b)
{
	float raised;

	raised = pow(a, b);

	return raised;
}

float Largest(float n1, float n2)
{
	float largest;

	if (n1 > n2)
	{
		return largest = n1;
	}

	else
		return largest = n2;
}

float Smallest(float temp, float temp2)
{
	float smallest;

	if (temp < temp2)
	{
		smallest = temp;
	}
	else smallest = temp2;

	return smallest;
}