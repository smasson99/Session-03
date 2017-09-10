#pragma once

class IntArray
{
public:
    IntArray(unsigned int size);
    IntArray(IntArray& instance);
    ~IntArray();
    int get(int index);
    void set(unsigned int index, int value);
    unsigned int Size();
private:
    int* array;
    unsigned int size;
};