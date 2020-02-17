/*********************************************************************************
Morgan Hughes
CS 317
Dr. Brady Rimes
11 March 2019
Sum of Digits Program
This program calculates what three numbers can be represented by the sum of the
cubes of their digits.
***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int sum;
	int digit;

	for (int i = 154; i <= 450;  i++)
	{
		n = i;
		sum = 0;

		while (n > 0)
		{
			digit = n % 10;
			sum += pow(digit, 3.0);
			n /= 10;
		}

		if (sum == i)
		{
			cout << i << endl;
		}
	}

	return 0;
}