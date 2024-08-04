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

    /*
        The variable highestIndex is used to track the highest index that contains a value.
        For example, consider the following array:

        __________________________________________________________________________
        |      |       |        |         |         |       |         |          |
        |  45  |  87   |   __   |   39    |   __    |   24  |   __    |   __     |
        |      |       |        |         |         |       |         |          |
        __________________________________________________________________________

        In this array, the highestIndex would be 6 (using one-based indexing).
    */
    int highestIndex;

    void grow(int newCapacity)
    {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < this->highestIndex; i++)
        {
            newArray[i] = this->array[i];
        }

        delete this->array;
        this->array = newArray;
        this->capacity = newCapacity;
        newArray = NULL;
    }

public:
    myDynamicArray(int capacity)
    {
        this->length = 0;
        this->highestIndex = 0;
        this->capacity = capacity;

        this->array = new int[capacity];

        for (int i = 0; i < this->capacity; i++)
        {
            this->array[i] = INT_MIN;
        }
    }

    void push(int value)
    {
        if (this->highestIndex == this->capacity)
        {
            this->grow(this->capacity + 1);
        }

        this->array[this->highestIndex] = value;
        this->highestIndex++;

        this->length++;
    }

    void push(vector<int> &arr)
    {
        if ((this->capacity - this->highestIndex) < arr.size())
        {
            int newCapacity = this->capacity + arr.size() - (this->capacity - this->highestIndex);

            this->grow(newCapacity);
        }

        int j = 0;
        for (int i = this->highestIndex; i < this->highestIndex + arr.size(); i++)
        {
            this->array[i] = arr[j];
            j++;
        }
        this->length += arr.size();
        this->highestIndex += arr.size();
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
