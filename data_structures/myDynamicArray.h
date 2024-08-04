#ifndef MYDYNAMICARRAY_H
#define MYDYNAMICARRAY_H

#include <iostream>
#include <vector>
using namespace std;

class myDynamicArray
{
private:
    int *array;

    int length;
    int capacity;

public:
    myDynamicArray(int capacity)
    {
        this->length = 0;
        this->capacity = capacity;

        this->array = new int[capacity];

        for (int i = 0; i < this->capacity; i++)
        {
            array[i] = INT_MIN;
        }
    }

    void show()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout << this->array[i] << "\n";
        }
    }

    int getLength()
    {
        return this->length;
    }
};

#endif // MYDYNAMICARRAY_H
