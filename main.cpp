#include <iostream>
#include "./data_structures/myDynamicArray.h"

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, INT_MIN, 7, 4, 5, INT_MIN};

    myDynamicArray *dynamicArray = new myDynamicArray(arr);

    dynamicArray->pushFront(99);

    dynamicArray->show();

    return 0;
}
