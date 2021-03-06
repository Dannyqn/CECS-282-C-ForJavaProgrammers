//
//Created by Danny Nguyen on 2/20/18 
//ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

const int V_MEMO_SIZE = 100;
int List[V_MEMO_SIZE];
int fill(int* const);
bool valid(int const);
void dump(const int* const memory);


/*
	*fills in the virtual memory locations
	*Precondition:array of integers
	*postcondition: an integer value determines count of values entered
*/
int fill(int* arrayName)
{
	int i = 0;
	int num = 0;
	int count = 0;
	while (num >= 0)
	{
		std::cout << "Enter an integer between 25 and 45: " << std::endl;
		std::cin >> num;
		if (valid(num))
		{
			arrayName[i] = num;
			std::cout << "Added" << std::endl;
			count++;
			i++;
		}
		else if (num > 0)
		{
			std::cout << "Enter a valid Integer: " << std::endl;
		}
		else {
			return count;
		}
	}
	return count;
}
/*
	*validates if the number is valid 
	*precondition: an integer 
	*postcondition: returns a boolean value
*/
bool valid(int number)
{
	if (number > 24 && number < 46)
	{
		return true;
	}
	return false;
}
/*
	*returns all the contents of the memory
	*Preconditon: n/a
	*Postcondition: n/a
*/
void dump(const int *const memory)
{
	std::cout << std::endl << "MEMORY:\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "\t" << i;
	}
	std::cout << std::endl;
	for (int i = 0; i <100; i += 10)
	{
		if (i == 0)
		{
			std::cout << std::noshowpos << "  " << i;
		}
		else {
			std::cout << std::noshowpos << " " << i;
		}
		for (int j = 0; j < 10; j++) {
			std::cout << "   " << std::showpos << std::setfill('0') << std::setw(5) << std::internal << memory[j + i];
		}
		std::cout << std::endl;
	}
}
int main()
{
	std::cout << "Hello, Memory Fill!\n";
	fill(List);
	dump(List);
	return 0;
}

