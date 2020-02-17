/*********************************************************************
Morgan Hughes 
5 January 2020
CS 318
DR. Brady Rimes
Pointer Statistics
This program uses pointers to manipulate an array and compute the mean
of the array, the median, the mode, and reverse the array, and then
print the first 32 values of the array, with 8 values per outfile.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

ofstream outfile;
ifstream infile;

//Prototypes
void Read(int *ptr, int counter); //read vals into ary
int Counter(int *ptr, int counter); //get count of array
void Swap(int *num1, int *num2); //to swap elements in reverse
void Sort(int *ptr, int counter); //sort array in ascending order 
void Print(int *ptr, int counter); //print sorted array & unsorted
float Mean(int *ptr, int counter); //calculate mean of sorted array
int Mode(int *ptr, int counter); //compute mode of sorted array
float Median(int *ptr, int counter); //compute median of array
void Reverse(int *ptr, int counter); //reverse array
void PrintReverse(int *ptr, int counter); //print only the first 32 elements of the reverse array w/ 8 per line.
  

int ary[100];


int main()
{
	//open files
	infile.open("numbers.txt");

	outfile.open("NumsReport.txt");


 
	//dynamically allocate array
	int *ptr;
	ptr =  new int [100];

	//declare variables
	int counter = 0;
	float mean;
	int mode = 0;
	float median = 0.0;

      //declare ptr to ary
	ptr = ary;
	outfile << "******POINTER STATISTICS********\n";
	
	//to get size of array
	counter = Counter(ptr, counter);

     outfile << endl << "The unsorted array: \n"; //print unsorted arrays

	Read(ptr, counter); //read in vals
	
	Sort(ptr, counter); //sort array

	outfile << endl;

	Print(ptr, counter); //print sorted ary

	
	 mean = Mean(ptr, counter); //report mean if ary to file                        //setp decimal precision to (1)
	 outfile << endl <<  "The mean of the array is: " << fixed << showpoint << setprecision(1)  << mean  << endl;

	 mode = Mode(ptr, counter); //report mode 
	 outfile << endl << "The mode of the array is: " << mode << endl;

	 median = Median(ptr, counter); //report median 
	 outfile << endl << "The median of the array is: " << median << endl;


	//Reverse array and then Print first 32 vals 
         Reverse(ptr, counter);

		 PrintReverse(ptr, counter);
	



		 //delete array
		 delete[] ptr;


	outfile.close(); //flush out buffers
	return 0; //terminate program

}

int Counter(int *ptr, int counter)
{

	while (!infile.eof()) 
	{
		infile >> *ptr;
		                 //read in and increment counter
                        //to get count of array
			  counter++;
        
	}
	cout << counter;
	return counter;
}

void Read(int *ptr, int counter)
{

	for(int i = 0;  i < counter; i++)
	{
		infile >> *ptr;

		cout << setw(3) << *ptr++ << " ";

		//*ptr++;

		if (i + 1 % 8 == 0)
		{
			cout << endl;
		}
	}

}

void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;      //swap vals for reverse
}
        

void Sort(int *ptr, int counter)
{
	int temp;

	for (int i = 0; i < counter; i++) //nested loop necessary for sort 
	{
		
		for (int j = i + 1; j < counter; j++)
		{
			if (*(ptr + j) < *(ptr + i))
			{
				
				temp = *(ptr + i);         //compare element >< assign 
				                                      //to temp
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = temp;
			    
				  
			}

		}
		
	}

}

void Print(int *ptr, int counter)
{
	outfile << endl << "The sorted array is: \n";
	for (ptr = ary; ptr < &counter; ptr++)
	{

		outfile << setw(3) << *ptr << " ";
		if (*(ptr + 1) % 8 == 0)             //traverse through array printing 
		{
			outfile << endl;
		}

	}
	outfile << endl;

}

float Mean(int *ptr, int counter)
{
	ptr = ary;
	float s = 0;
	float mean;
	for (int i = 0; i < counter; i++)
	{
		s = s + *ptr;
		ptr = ptr++;
		                                  //traverse through array summing elements
	}
	mean = s / counter;
	//compute mean just as avg

	return mean;
}
int Mode(int  *ptr, int counter)
{
	 ptr = ary;
	int mode = *ptr;
	int count = 1;
	int countMode = 1;


	for (int i = 1; i  < counter; i++)
	{
		if (*(ptr + i) == *ptr)
		{
			count++;                //if element = itself, increment the count
		 }
		else {
			if (count > countMode)
			{
				countMode = count;     //update element with > count
				mode = *ptr;
			}
			count = 1;

			*ptr = *(ptr + i);

		}
			
			
    }
       return mode;
}


float Median(int *ptr, int counter)
{
	int middle;
	float median;

	middle = counter / 2.0;

	if (counter % 2 == 0)       //if array has even # of elements avg 2 middle ones
	{
		median = (*(ptr + middle) + *(ptr + middle + 1)) / 2.0;
	}
	else {
		median = *(ptr + middle + 1);
	}

	return median;
}
	
void Reverse(int *ptr, int counter)
{
	int *ptr2 = ary + counter - 1;  //begin rversing array

	while (*ptr < *ptr2)
	{
		Swap(ptr, ptr2);      //call swap fuction to reverse ary

		ptr++;
		ptr2--;
	}


}

void PrintReverse(int *ptr, int counter)
{
	//set ptr to beginning of array
	 ptr = ary;

	outfile << endl << "The reversed array with only the first 32 values:  \n";

	for (int i = 0; i < counter - 60; i++)
	{
		outfile << setw(3) << *(ptr + 1) << " ";
		if ((i + 1) % 8 == 0) //8 # per line outout as requested 
		{
			outfile << endl;
		}

	}
	outfile << endl;
}  
