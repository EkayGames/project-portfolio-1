#pragma once
#include <cctype>
#include <iostream>
#include <limits>

namespace Helper
{
	//Line
	static void Line()
	{
		std::cout << "===============\n";
	}

	//Detect if char(s) is integer
	static bool IsInteger(const char* input)
	{
		bool isInteger = true;

		if (input[0] == '\0')
		{
			return false;
		}

		int i = 0;

		if (input[0] == '-') i = 1;

		for (; input[i] != '\0'; i++)
		{
			if (!std::isdigit(input[i]))
			{
				isInteger = false;
			}
		}

		return isInteger;
	}

	//Print binary value of integer
	static void PrintIntegerBinary(int* input)
	{
		std::string binaryOutput = "";

		for (int i = ((sizeof(*input) * 8) - 1); i >= 0; i--)
		{
			if (*input & (1 << i))
			{
				binaryOutput += "1";
			}
			else binaryOutput += "0";
		}

		std::cout << binaryOutput << "\n";
	}

	//Bubble sort
	static void BubbleSort(int* nums, int size)
	{
		bool sorted = false;

		while (!sorted)
		{
			sorted = true;

			for (int i = 0; i < size - 1; i++)
			{
				if (nums[i] > nums[i + 1])
				{
					int temp = nums[i];
					nums[i] = nums[i + 1];
					nums[i + 1] = temp;
					sorted = false;
				}
			}
		}
	}

	//ClearInputBuffer
	static void ClearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//Clear console
	static void ClearConsoleWindow()
	{
		std::system("cls");
	}

	//Get menu choice
	static unsigned int GetMenuChoice(unsigned int min, unsigned int max)
	{
		unsigned int userInput;

		while (true)
		{
			std::cin >> userInput;
			//ClearInputBuffer();

			if (userInput >= min && userInput <= max)
			{
				return userInput;
			}
			else
			{
				std::cout << "Invalid input. Enter again: ";
			}
		}

	}

	//Pause console 
	static void PauseConsoleWindow()
	{
		std::cin.get();
	}

	//Memory leak detection code PUT AT START OF MAIN
	static void MemoryLeakDetector(int line)
	{
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(line); // set block of memory to find memory leak
		_CrtDumpMemoryLeaks();
	}

	//Is positive integer
	static bool IsPositiveInteger(const int& input)
	{
		bool isPositive;

		if (input <= 0)
		{
			isPositive = false;
		}
		else isPositive = true;

		return isPositive;
	}

	//Random number generator
	static int RandomNumberGenerator(const int min, const int max)
	{
		int randNum = 0;
		randNum = rand() % (max - min + 1) + min;

		return randNum;
	}

	//Coin flip true false
	static bool CoinFlip()
	{
		bool result = rand() % 2;
		return result;
	}
}
