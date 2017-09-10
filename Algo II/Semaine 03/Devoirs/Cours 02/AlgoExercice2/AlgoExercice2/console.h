#ifndef CONSOLE_H
#define CONSOLE_H

#include "intArray.h"

/**
 * \brief Contains simple features to interact with the console.
 */
class Console
{
public:

	/**
	* \brief Show a text in console.
	*
	* \param text		Text to show in the console.
	*/
	void showText(char* text);

	/**
	* \brief Show a message in console. Waits for user to input a key before
	*        returning.
	*
	* \param pauseText		Text to show in the console.
	*/
	void showMessage(char* pauseText);

	/**
	 * \brief Show the provided int array in the console.
	 * \param array			Int array to show.
	 * \param arraySize		Array size.
	 */
	void showIntArray(int array[], int arraySize);

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
	int readInt(char* promptText, char* notANumberErrorText);

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
	IntArray readIntArray(int arraySize, char* numberPromptText, char* notANumberErrorText);
};

#endif
