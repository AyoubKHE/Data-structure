#include <iostream>
#include "./data_structures/myDynamicArray.h"

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, INT_MIN, 9, 10};

    myDynamicArray *dynamicArray = new myDynamicArray(arr);

    dynamicArray->removeLastElement();

    dynamicArray->show();

    return 0;
}
