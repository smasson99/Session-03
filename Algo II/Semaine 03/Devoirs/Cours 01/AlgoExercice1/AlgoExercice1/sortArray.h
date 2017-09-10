#pragma once

#include <iostream>
#include <string>


int* SortArray(int* myArray, int* length)
{
    for (int i = *length - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (myArray[j + 1] < myArray[j])
            {
                int temp = myArray[j + 1];
                myArray[j + 1] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
    return myArray;
}