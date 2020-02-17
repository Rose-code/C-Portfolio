/*********************************************************************************
Morgan Hughes
7 November 2019
CS 318
Dr. Rimes
Postfix evaluation program 
*********************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>	

using namespace std;

//Prototypes
long long int EvaluatePostfix(string expression); //function to evaluate postfix expression and return output
long long int PerformOperation(char operation, long long int operand1, long long int operand2);  //function to perform an operationand return output
bool IsOperator(char c); //function to verify whether a char is operator symbol or not
bool IsNumericDigit(char c); //function to verify whether a character is numeric digit

int main()
{
	string expression;
    string line; 

    ifstream infile("PostFix.dat"); //open file
	ofstream outfile("PostFixReport.txt");


	outfile << "The postfix evaluation of all expressions in the file are: \n";
	

	while (getline(infile, line))//while there are lines in file
	{
		outfile << line; //print per line
		long long int result = EvaluatePostfix(line); //eval post exp

		outfile << "Output = " << result << "\n";
	}

	infile.close();

	return 0;
}

long long int EvaluatePostfix(string expression)
{
	//declaring stack from standard template lib in C++
	stack<long long int> S;

	for (int i = 0; i < expression.length(); i++)
	{
		//scanning each char from left

		if (expression[i] == ' ' || expression[i] == ',')
			continue;

		else if (IsOperator(expression[i])) //if char is operator. pop 2 elements from stack, perform operation, push result back
		{
			//pop 2 operands
			long long int operand2 = S.top(); S.pop();
			long long int operand1 = S.top(); S.pop();

			//perform
			long long int result = PerformOperation(expression[i], operand1, operand2);

			//push back result of operation on stack
			S.push(result);
		}
		else if (IsNumericDigit(expression[i]))
		{
			//extract numeric operand from the string
			//keep incrementing as long as getting numeric digi
			int operand = 0;

			while (i < expression.length() && IsNumericDigit(expression[i]))
			{
				//for num w one or more digits, scanning from left to right
				//everytime get a digit from right, multiply current total in operand by 10
				//add new digit
				operand = (operand * 10) + (expression[i] - '0');
				i++;
			}
			//dec i bc it will be inc in inc section of loop once again
			i--;

			//push operand on stack
			S.push(operand);
		}
	}

	//if expression is in correct format, stack will finally have 1 el (output)
	return S.top();
}

bool IsNumericDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	else
		return false;
}

bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		return true;
	}
	else
		return false;
}

long long int PerformOperation(char operation, long long int operand1, long long int operand2)
{
	if (operation == '+')
	{
		return operand1 + operand2;
	}

	else if (operation == '-')
	{
		return operand1 - operand2;
	}

	else if (operation == '*')
	{
		return operand1 * operand2;
	}

	else if (operation == '/')
	{
		return operand1 / operand2;
	}

	else
		cout << "Unexpected ERROR\n";

	return -1;
}