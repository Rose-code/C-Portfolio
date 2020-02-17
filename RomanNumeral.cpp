/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
26 February 2019
Roman Numeral Converter Program
This program reads in roman numerals, converts them to base 10 numbers, and 
sends the report to an outfile
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int number(char roman);

ifstream infile;

int main()
{

	//Declare Variables 
	//int number;
	int val;
	//string roman;
	int dec;
	int roman1;

	dec = 0;

	string roman;
	while (!infile.eof())
	{
		infile >> roman;
			for (int i = 0; i < roman.size(); i++)
			{
				if (number(roman)[i]) >= number(roman[i + 1]))
					dec += number(roman[i]);
				else
					dec -= number(roman[i]);
				

			}
			cout << "*****************************\n"
		       << roman << " \t" << dec << endl
		      << "*****************************\n";
		
			
	}

	infile.close();
			
			return 0;





} 


int nummber(char roman)
{
	int val = 0;

  switch (roman)
	{
	case 'I': 
			val = 1;
			break;

	case 'V': 
				val = 5;
				break;

	case 'X' : 
					val = 10;
					break;

	case 'L' : 
						val = 50;
						break;
						
	case 'C': 
							val = 100;
							break;

	case 'D' : 
								val = 500;
								break;

	case 'M' : 
									val = 1000;
									break;

								default:
									val = 0;

									
	}

  return val;

}
   
	