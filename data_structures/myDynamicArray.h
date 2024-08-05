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

    /*
        The `closestEmptyPostionFrom` function is used to find the closest empty position in the array starting from a given position.
        It iterates through the array starting from the specified position until it finds an element with the value `INT_MIN`,
        which indicates an empty position.
        If it finds an empty position, it returns the index of that position.
        If no empty position is found after the specified position, it returns - 1.
    */
    int closestEmptyPostionFrom(int position)
    {
        for (int i = position; i < this->capacity; i++)
        {
            if (this->array[i] == INT_MIN)
            {
                return i;
            }
        }
        return -1;
    }

public:
    void shiftElementsRight(int from, int to)
    {
        for (int i = from; i > to; i--)
        {
            this->array[i] = this->array[i - 1];
        }

        this->array[to] = INT_MIN;
    }

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

    myDynamicArray(vector<int> &arr)
    {
        this->length = 0;
        this->highestIndex = 0;
        this->capacity = arr.size();

        this->array = new int[this->capacity];

        for (int i = 0; i < this->capacity; i++)
        {
            if (arr[i] != INT_MIN)
            {
                this->length++;
                this->highestIndex = i + 1;
            }
            this->array[i] = arr[i];
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

    void pushFront(int value)
    {
        if (this->array[0] == INT_MIN)
        {
            this->array[0] = value;
            if (this->highestIndex == 0)
            {
                this->highestIndex = 1;
            }
        }
        else
        {
            int closestEmptyPostion = this->closestEmptyPostionFrom(1);

            if (closestEmptyPostion != -1)
            {
                this->shiftElementsRight(closestEmptyPostion, 0);
                if (closestEmptyPostion + 1 > this->highestIndex)
                {
                    this->highestIndex++;
                }
            }
            else
            {
                this->grow(this->capacity + 1);

                this->shiftElementsRight(capacity - 1, 0);

                this->highestIndex++;
            }

            this->array[0] = value;
        }

        this->length++;
    }

    void pushFront(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            this->pushFront(arr[i]);
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
