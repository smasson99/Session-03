#include "console.h"
#include <iostream>
#include <string>

void Console::showText(char* text)
{
	std::cout << text << std::endl;
}

void Console::showMessage(char* pauseText)
{
	std::cout << pauseText;
	std::cin.get();
	std::cout << std::endl;
}

void Console::showIntArray(int array[], int arraySize)
{
	std::cout << "{";
	for (int i = 0; i < arraySize; i++)
	{
		if (i != 0)
		{
			std::cout << " ,";
		}
		std::cout << array[i];
	}
	std::cout << "}" << std::endl;
}

int Console::readInt(char* promptText,
	char* notANumberErrorText)
{
	std::string rawInput;
	int convertedInput;

	bool isInputValid = false;
	while (!isInputValid)
	{
		std::cout << promptText << std::endl;
		getline(std::cin, rawInput);

		try
		{
			convertedInput = stoi(rawInput);
			isInputValid = true;
		}
		catch (std::invalid_argument e)
		{
			std::cout << notANumberErrorText << std::endl;
		}
	}
	return convertedInput;
}

IntArray Console::readIntArray(int arraySize,
                           char* numberPromptText,
                           char* notANumberErrorText)
{
	IntArray numbers = IntArray(arraySize);
	for (int i = 0; i < arraySize; i++)
	{
        numbers.set(i, readInt(numberPromptText, notANumberErrorText));
	}
	return numbers;
}
