#include "stdafx.h"
#include "common.h"


int intFromBinary(const std::string& number) {
	
	int num = 0;
	bool neg = false;
	std::string a = number;
	if (a.at(0) == '1')
	{
		neg = true;
		for (int x = a.length() - 1; x >= 0; x--)
		{
			if (a.at(x) == '1')
				a.at(x) = '0';
			else a.at(x) = '1';
		}
		a.at(a.length() - 1) += 1;
		for (int x = a.length() - 1; x >= 0; x--)
		{
			if (a.at(x) == '2')
			{
				if (x - 1 >= 0)
				{
					if (a.at(x - 1) == '1')
						a.at(x - 1) = '2';
					if (a.at(x - 1) == '0')
						a.at(x - 1) = '1';
					a.at(x) = '0';
				}
			}
			else if (a.at(x) == '3')
			{
				if (x - 1 >= 0)
					a.at(x - 1) += '2';
				a.at(x) = '1';
			}
		}
		if (a.at(0) == '2')
			a.at(0) = '0';
		else if (a.at(0) == '3')
			a.at(0) = '1';
	}
	for (int x = a.length() - 1; x >= 0; x--)
	{
		if (a.at(x) == '1')
			num += pow(2.0, a.length() - x - 1);
	}
	if (neg)
		num = num*-1;
	return num;

}

std::string binaryFromInt(int x) {

	std::string binary = "";
	int mask = 1;
	for (int i = 0; i < 31; i++)
	{
		if ((mask&x) >= 1)
			binary = "1" + binary;
		else
			binary = "0" + binary;
		mask <<= 1;
	}

	return binary;

}

std::string binaryFromInt(char x) {

	std::string binary = "";
	char mask = 1;
	for (int i = 0; i < 31; i++)
	{
		if ((mask&x) >= 1)
			binary = "1" + binary;
		else
			binary = "0" + binary;
		mask <<= 1;
	}

	return binary;

}

void printIntAsBinary(int x)
{
	std::string str = binaryFromInt(x);
	printf("%s\n", str.c_str());
}



