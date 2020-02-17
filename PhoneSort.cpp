/*******************************************************************************************
Morgan Hughes
7 October 2019
Phone Sort Program
CS 318
Dr. Brady Rimes
This program
********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>

using namespace std;

class PhoneBook
{
public: string last_name;
		string first_name;
		string Number;

		PhoneBook(string f, string l, string n)
		{
			this->first_name = f;
			this->last_name = 1;
			this->Number = n;
		}
};

bool Compare_IDS_Predicate_Asc(PhoneBook First, PhoneBook Next)
{
	//First argument stays first (return true)
	if (First.last_name < Next.last_name)
		return true;

	//first argument goes next (swap) (return false)
	if (First.last_name > Next.last_name)
		return false;
}

int main()
{
	string line;
	string firstname = "";
	string word;
	string lastname;
	string fname = "";
	int flag = 0;

	list <class PhoneBook> gqlist1;

	ifstream infile("namesAndPhoneV2.txt");
	ofstream outfile("PhoneReport.txt");

	if (!infile)
	{
		cout << "Error opening file\n";
	}

	while (getline(infile, line))
	{
		istringstream iss(line);
		firstname = "";
		lastname = "";

		while (iss >> word) //strip the line into words
		{
			if (word == "lastname" || word == "surname")
			{
				flag = 1;

			}

			if (word != "lastname" || word != "surname")
			{
				if (flag == 1)
				{
					lastname = word; //set string last name to next word
					flag = 0;
				}
				else
					firstname += word + " "; //other words are taken as first name w/ nums
			}
		}

		int j = 0;
		fname = firstname;
		for (int i = 0; i < firstname.length(); i++)
		{
			if (!(firstname[i] >= '0' && firstname[i] <= '9'))
			{
				j++;
			}
		}
		fname = firstname.substr(0, j - 2); //take substring of firstname upto length of j-2

		int len = firstname.length(); //calculate length of first name

		string no = firstname.substr(j - 2, len); //taking substring to extract #

		PhoneBook b(fname, lastname, no); //make the object of the class and assign the vals
	  
		gqlist1.push_back(b); //insert the object to the list

	}

	outfile << "Without Sort:\n";

	for (PhoneBook b : gqlist1)
	{
		outfile << b.first_name << b.last_name << " " << b.Number << endl;
	}

	gqlist1.sort(Compare_IDS_Predicate_Asc);

		outfile << "\n\nSort by Last Name:\n\n";

	for (PhoneBook b : gqlist1)
	{
		outfile << b.first_name << b.last_name << " " << b.Number << endl;
	}

	outfile.close();

	return 0;
}