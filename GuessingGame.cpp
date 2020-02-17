/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
6 March 2019
Guessing Game Program
This program generates random numbers for the user to guess, and keeps count of how 
many guesses it takes to guess the correct number. It then outputs the report to
a file. 
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib> //Needed for rand and srand 
#include <ctime> //Needed for time fuction to generate random #'s

using namespace std;

ofstream outfile; //File the report will be sent to 

int main()
{

	//Constants
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 100;

	//Declare variables
	int guess; //Variable for users guess 
	int count; //Variable for how many guesses it takes 
	string play_again; //Variable for yes or no 
	int y; //Variable for random # generated 
	string yes;
	string no;
	
	//Assign variables to value
	count = 0;
	guess = 1;

	//Open the file
	outfile.open("GuessingGame.txt");

	//Get system time
	unsigned int seed = int(time(0));

	//Seed random # generator 
	srand(seed);

	//Formula for random #'s
	y = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;


	count++;

	//Prompt the user
	cout << "****Welcome to the Guessing Game****\n"
		<< "Guess what the number is\n";

	cin >> guess;

	//Prompt the user 
	while(guess!= y)
	{
        
	

	   if (guess > y)
	   {
		cout << "*******************************\n"
			<< "That's too high, try again!\n"
			<< "*******************************\n";
			cin >> guess;
			
	   }

	   else if (guess < y)
	   {
		cout << "*******************************\n"
			<< "That's too low, try again!\n"
			<< "*******************************\n";
		 cin >> guess;

	   }
	    
       
	   count++; //Calculate how many guesses
	   

	} 
       
	   cout << "*********************************************\n"
			   << "That's correct it took you " << count << " times\n"
			   << "*********************************************\n";
	   
	   auto coutbuf = std::cout.rdbuf(outfile.rdbuf()); //Save and redirect cout to outfile
	


		system("PAUSE");

		outfile.close();    


	return 0;


}
