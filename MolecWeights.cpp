/**************************************************************************************
Morgan Hughes
26 September 2019
CS 318
Dr. Brady Rimes
Molecular Weights Sort and Search
This program
****************************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>


using namespace std;

struct element
{
	string sym;
	double wt;
};

//Prototypes
double findWeight(element table[], int size, string srch);

int main()
{
	element toe[40]; //table of elements (sorted)
	element el; //new name assignment for element

	ifstream elementfile("Element.doc");
	ifstream formulafile("Formula.doc");
	ofstream reportfile("MolecularReport.txt");

	if (!elementfile || !formulafile)
	{
		cout << "error opening files\n";

		elementfile.close();
		formulafile.close();
		
	}

	//declare variables
	int n = 0;
	int i;
	int j;
	string formula;
	string sym;
	int count;
	double at_weight;

	elementfile >> el.sym >> el.wt;

	do
	{
		//insert to keep sorted order in tact
		for (i = 0; i < n; i++)
		{
			if (el.sym.compare(toe[i].sym) < 0)
				break;
		}

		//shift to right to make space for insertion
		for (j = n - 1; j >= i; j--)
			toe[j + 1] = toe[j];
		toe[i] = el;
		n++;

		elementfile >> el.sym >> el.wt;
	} while (elementfile.peek() != EOF);

	elementfile.close();

	for (i = 0; i < n; i++)
	{
      reportfile << toe[i].sym << " : " << toe[i].wt << "\n";
	}
		
	reportfile << setw(35) << left << "Formula"
		<< "Atomic Weight\n"
		<< setw(35) << left << "------"
		<< "------------\n";

	formulafile >> formula;

	do
	{
		at_weight = 0.0f;
		sym = "";

		for (i = 0; i < formula.size(); i++)
		{
			if (formula[i] >= 'A' && formula[i] <= 'Z')
			{
				//capital alpha implies new symbol'
				if (sym.size() > 0)
				{
					at_weight += findWeight(toe, n, sym);

					reportfile << "(" << sym << ": " << findWeight(toe, n, sym) << ")";
				 }
				sym = "";
				sym += formula[i];
			}
			else if (formula[i] >= 'a' && formula[i] <= 'z')
			{
				sym += formula[i];
			}
			if (formula[i] == '(')
			{
				int closebrace = formula.find(")", i++);
				string intstring = formula.substr(i++, closebrace - i - 1);

				count = atoi(intstring.c_str());

				at_weight += findWeight(toe, n, sym) * count;

				reportfile << "(" << sym << ": " << findWeight(toe, n, sym) << ")";

				sym = ""; //reset symbol string
				i = closebrace; //move counter to closing brace
			}
		}
		//check if last symbol is remaining to be processed
		if (sym.size() > 0)
		{
			at_weight += findWeight(toe, n, sym);

			reportfile << "(" << sym << ": " << findWeight(toe, n, sym) << ")";
		}

		reportfile << setw(35) << left << formula << at_weight << "\n";

		formulafile >> formula;
	} 
	while (formulafile.peek() != EOF);

	formulafile.close();

	return 0;
}

//Function to perform binary search and return weight
double findWeight(element table[], int size, string srch)
{
	//declare variables
	int beg = 0;
	int end = size - 1;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (srch.compare(table[mid].sym) == 0)

			return table[mid].wt;
		

		if (srch.compare(table[mid].sym) > 0) //move to second half of data
		
			beg = mid + 1;
		   
		else
		
            end = mid - 1;	
	}

	return 0.0f; //not found, should not arise at all

}