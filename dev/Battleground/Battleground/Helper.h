#pragma once
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

enum class Color
{
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
};

enum class BackgroundColor
{
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
};

enum class TextType
{
	BOLD,
	UNDERLINE,
	DOUBLEUNDERLINE
};



namespace Helper
{
	//Reset text colors and type
	static void ResetText()
	{
		std::cout << "\033[0m";
	}

	//Change text color
	static void ChangeTextColor(Color color)
	{
		switch (color)
		{
		case Color::RED:
			std::cout << "\033[31m";
			break;
		case Color::GREEN:
			std::cout << "\033[32m";
			break;
		case Color::YELLOW:
			std::cout << "\033[33m";
			break;
		case Color::BLUE:
			std::cout << "\033[34m";
			break;
		case Color::MAGENTA:
			std::cout << "\033[35m";
			break;
		case Color::CYAN:
			std::cout << "\033[36m";
			break;
		case Color::WHITE:
			std::cout << "\033[37m";
			break;
		}
	}

	static void ChangeTextBackground(BackgroundColor color)
	{
		switch (color)
		{
		case BackgroundColor::RED:
			std::cout << "\033[41m";
			break;
		case BackgroundColor::GREEN:
			std::cout << "\033[42m";
			break;
		case BackgroundColor::YELLOW:
			std::cout << "\033[43m";
			break;
		case BackgroundColor::BLUE:
			std::cout << "\033[44m";
			break;
		case BackgroundColor::MAGENTA:
			std::cout << "\033[45m";
			break;
		case BackgroundColor::CYAN:
			std::cout << "\033[46m";
			break;
		case BackgroundColor::WHITE:
			std::cout << "\033[47m";
			break;
		}
	}

	static void ChangeTextType(TextType type)
	{
		switch (type)
		{
		case TextType::BOLD:
			std::cout << "\033[1m";
			break;
		case TextType::UNDERLINE:
			std::cout << "\033[4m";
			break;
		case TextType::DOUBLEUNDERLINE:
			std::cout << "\033[21m";
			break;
		}
	}


	//Print text of color
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(Color color, PrintedText&&... text)
	{
		ChangeTextColor(color);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text of backgroundcolor
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(BackgroundColor background, PrintedText&&... text)
	{
		ChangeTextBackground(background);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text of type
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(TextType type, PrintedText&&... text)
	{
		ChangeTextType(type);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text of color with background
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(Color color, BackgroundColor background, PrintedText&&... text)
	{
		ChangeTextColor(color);
		ChangeTextBackground(background);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text of color with type
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(Color color, TextType type, PrintedText&&... text)
	{
		ChangeTextColor(color);
		ChangeTextType(type);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text of background with type
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(BackgroundColor background, TextType type, PrintedText&&... text)
	{
		ChangeTextBackground(background);
		ChangeTextType(type);
		(std::cout << ... << text);
		ResetText();
	}

	//Print text with color background color and type
	template <typename... PrintedText> //Declare template to use for input text in print function
	static void PrintText(Color color, BackgroundColor background, TextType type, PrintedText&&... text)
	{
		ChangeTextColor(color);
		ChangeTextBackground(background);
		ChangeTextType(type);
		(std::cout << ... << text);
		ResetText();
	}

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
	/*static void ClearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}*/

	//Clear console
	static void ClearConsoleWindow()
	{
		std::system("cls");
	}

	//Get menu choice
	static unsigned int GetMenuChoice(unsigned int min, unsigned int max)
	{
		std::string userInput;
		unsigned int inputInt;

		while (true)
		{
			std::getline(std::cin, userInput);

			if (IsInteger(userInput.c_str()))
			{
				try
				{
					inputInt = std::stoul(userInput);

					if (inputInt <= max && inputInt >= min)
					{
						return inputInt;
					}
					else std::cout << "Invalid input. Enter number between " << min << " and " << max << ": ";
				}
				catch (...)
				{
					std::cout << "Invalid input. Enter number between " << min << " and " << max << ": ";
				}
			}
			else std::cout << "Invalid input. Enter number between " << min << " and " << max << ": ";



		}

	}

	//Pause console 
	static void PauseConsoleWindow()
	{
		std::string input;
		std::getline(std::cin, input);
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
