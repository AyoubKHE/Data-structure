#include <iostream>
#include "./data_structures/myDynamicArray.h"

using namespace std;

int main()
{
    myDynamicArray *dynamicArray = new myDynamicArray(10);

    dynamicArray->push(1);
    dynamicArray->push(2);
    dynamicArray->push(3);

    vector<int> arr = {4, 5, 6, 7, 8, 9, 10};

    dynamicArray->push(arr);

    vector<int> arr2 = {95, 96, 97, 98, 99, 100};

    dynamicArray->push(arr2);

    dynamicArray->show();

    return 0;
}
