#include "intArray.h"

IntArray::IntArray(unsigned int size)
{
    this->size = size;
    array = new int[size];
}

IntArray::IntArray(IntArray& instance)
{
    size = instance.Size();
    array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = instance.get(i);
    }
}

IntArray::~IntArray()
{
    delete[] array;
}

int IntArray::get(int index)
{
    return array[index];
}

void IntArray::set(unsigned index, int value)
{
    array[index] = value;
}

unsigned int IntArray::Size()
{
    return this->size;
}