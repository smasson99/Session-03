#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

/**
* \brief Show a text in console.
*
* \param text		Text to show in the console.
*/
void showText(char* text)
{
	std::cout << text << std::endl;
}

/**
* \brief Show a message in console. Waits for user to press "Enter" before returning.
*        
* \param pauseText		Text to show in the console.
*/
void showMessage(char* pauseText)
{
	std::cout << pauseText;
	std::cin.get();
	std::cout << std::endl;
}

/*
 * Faire la fonction « showIntArray » ici
 */

/**
 * \brief Reads an integral number from console. Loop until the user
 *		  inputs a valid integral number.
 *		  
 * \param promptText			Prompt text to show, asking for a number.
 * \param notANumberErrorText	Text to show when user inputs an 
 *								invalid integral number. 
 *								
 * \return The number that the user entered.
 */
int readInt(char* promptText,
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

/**
 * \brief Reads an array from console. Loop until the user inputs valid integral numbers.
 * 
 * \param arraySize				Array size to ask.
 * \param numberPromptText		Prompt text to show, asking for a number.
 * \param notANumberErrorText	Text to show when user inputs an 
 *								invalid integral number.
 *								
 * \return The array of numbers that the user entered. Caller is responsable for array deletion.
 */
int* readIntArray(int arraySize,
                  char* numberPromptText,
                  char* notANumberErrorText)
{
    int* myArray = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        myArray[i] = readInt(numberPromptText, notANumberErrorText);
    }
	return myArray;
}

/// <summary>
/// Shows the contents of the array.
/// </summary>
/// <param name="arrayToShow">The array to show.</param>
/// <param name="length">The length of the array to show.</param>
void showIntArray(int* arrayToShow, int* length)
{
    std::cout << "Voici votre tableau :" << std::endl;
    std::cout << "{";
    for (int i = 0; i < *length; i++)
    {
        std::cout << arrayToShow[i];
        if (i < *length - 1)
            std::cout << " ,";
    }
    std::cout << "}" << std::endl;
}

#endif
