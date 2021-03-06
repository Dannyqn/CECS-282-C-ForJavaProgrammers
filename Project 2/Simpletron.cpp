//
//Simpletron.cpp : A simple computer that takes user inputs as "words" and converts and executes instructions based on the words
//
//
// Created by Danny Nguyen and Ashley Williams on 2/22/18
// Copyright © 2018 Danny Nguyen and Ashley Williams. All rights reserved.
//
#include "stdafx.h"
#include <iostream>
#include <iomanip>

void Fill();
int Execute();
void Dump();

const int MEMO_SIZE = 100;
int memory[MEMO_SIZE];
int input;
int accumulator = 0;
int instructionCounter = 0;
int operationCode = 0;
int operand = 0;
int instructionRegister = 0;

int main()
{
	std::cout << "*** Welcome to Simpletron! ***\n\n*** Please enter your program one instruction ***\n*** (or data word) at a time. I will type the ***\n";
	std::cout << "*** location number and a question mark (?).  ***\n*** You then type the word for that location. ***\n";
	std::cout << "*** Type the sentinel -99999 to stop entering ***\n*** your program. ***\n\n";
	Fill();
	std::cout << "\n*** Program loading completed ***\n*** Program execution begins ***\n\n";
	Execute();
	Dump();
    return 0;
}
/*
	*Fills in the memory array with user inputed "words"
	*Precondition: n/a
	*postconditon: n/a
*/
void Fill()
{
	for (int i = 0; i < MEMO_SIZE; ++i)
	{
		if (i < 10) {
			std::cout << "0" << i << " ? ";
		}
		else {
			std::cout << i << " ? ";
		}
		std::cin >> input;
		if (input == -99999) {
			break;
		}
		else
		{
			memory[i] = input;
			instructionCounter++;
		}
	}
}
/*
	*Executes instructions based on the words in the memory array
	*Precondition: n/a
	*Postcondition: returns 0
*/
int Execute()
{
	for (int i = 0; i < instructionCounter; ++i)
	{
		instructionRegister = std::abs(memory[i]);
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operationCode)
		{
		case 10://READ
			std::cin >> memory[operand];
			break;
		case 11://WRITE
			std::cout << memory[operand] << std::endl;
			break;
		case 20://LOAD
			accumulator = memory[operand];
			break;
		case 21: //STORE
			memory[operand] = accumulator;
			break;
		case 30://ADD
			accumulator += memory[operand];
			break;
		case 31://SUBTRACT
			accumulator -= memory[operand];
			break;
		case 32://DIVIDE
			if (memory[operand] != 0)
			{
				accumulator /= memory[operand];
			}
			else {
				std::cout << "*** Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***\n";
				return 0;
			}
			break;
		case 33://MULTIPLY
			accumulator *= memory[operand];
			break;
		case 40://BRANCH
			i = operand - 1;
			break;
		case 41://BRANCHNEG
			if (accumulator < 0)
			{
				i = operand - 1;
			}
			break;
		case 42://BRANCHZERO
			if (accumulator == 0)
			{
				i = operand - 1;
			}
			break;
		case 43://HALT
			std::cout << "*** Simpletron execution terminated ***\n";
			return 0;
		default:
			std::cout << "*** Invalid Operation Code ***\n*** Simpletron execution abnormally terminated ***\n";
			return 0;
		}
		if (accumulator > 9999 || accumulator < -9999)
		{
			std::cout << "*** Accumulator Overflow ***\n*** Simpletron execution abnormally terminated ***\n";
			return 0;
		}
	}
}
/*
	*returns the name and contents of each register and the complete contents of the memory
	*Precondition: n/a
	*Postcondition: n/a
*/
void Dump()
{
	std::cout << "REGISTERS:\naccumulator\t\t" << std::setfill('0') << std::internal<<std::setw(5) << std::showpos<<accumulator <<std::endl;
	if (instructionCounter < 10)
	{
		std::cout << std::noshowpos << "instructionCounter\t   0" << instructionCounter << std::endl;
	}
	else {
		std::cout << std::noshowpos << "instructionCounter\t   " << instructionCounter << std::endl;
	}
	std::cout << "instructionRegister\t" << std::setfill('0') << std::internal << std::setw(5) << std::showpos << instructionRegister << std::endl;
	if (operationCode < 10)
	{
		std::cout << std::noshowpos << "operationCode\t\t   0" << operationCode << std::endl;
	}
	else {
		std::cout << std::noshowpos << "operationCode\t\t   " << operationCode << std::endl;
	}
	if (operand < 10)
	{
		std::cout << "operand\t\t\t   0" << operand << std::endl;
	}
	else {
		std::cout << "operand\t\t\t   " << operand << std::endl;
	}
	std::cout << std::endl << "MEMORY:\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "\t" << i;
	}
	std::cout << std::endl;
	for (int i = 0; i <100; i+=10)
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

