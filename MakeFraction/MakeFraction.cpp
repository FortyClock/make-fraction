#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void div(unsigned __int64& up, unsigned __int64& down) // Euclidean algorithm 
{
	unsigned __int64 a = up; unsigned __int64 b = down;
	while (a != 0 and b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}
	unsigned __int64 nod = a + b;
	up /= nod;
	down /= nod;
}

void main()
{
	fstream fin("file.txt");

	map <unsigned __int64, unsigned __int64> up;   // numerator power metre
	map <unsigned __int64, unsigned __int64> down; // denominator power metre

	string str;
	int a, b;
	while (getline(fin, str)) // fill the counters
	{
		a = str[0] - 48; // numerator
		b = str[2] - 48; // denominator

		if (a == 4 || a == 8 || a == 9)
		{
			if (a == 4)
				up[2] += 2;
			if (a == 8)
				up[2] += 3;
			if (a == 9)
				up[3] += 2;
		}
		else
			up[a]++;
		if (b == 4 || b == 8 || b == 9)
		{
			if (b == 4)
				down[2] += 2;
			if (b == 8)
				down[2] += 3;
			if (b == 9)
				down[3] += 2;

		}
		else
			down[b]++;

		
	}


	int i;
	const int countNum = 10;
	for (i = 2; i < countNum; i++) // reduce the powers
	{
		int power = up[i] - down[i];

		if (power >= 0)
		{
			up[i] = power;
			down[i] = 0;

		}

		else
		{
			up[i] = 0;
			down[i] = abs(power);
		}

	}

	unsigned __int64 numUp = 1;
	unsigned __int64 numDown = 1;

	for (i = 2; i < countNum; i++) // calculate the  fraction
	{
		if (i == 4 || i == 8 || i == 9)
			continue;
		numUp *= pow(i, up[i]);
		numDown *= pow(i, down[i]);

		

	}

	div(numUp, numDown);
	cout << endl << numUp << '/' << numDown;
}