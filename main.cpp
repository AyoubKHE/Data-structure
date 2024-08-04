#include <iostream>
#include "./data_structures/myDynamicArray.h"

using namespace std;

int main()
{
    myDynamicArray *dynamicArray = new myDynamicArray(5);
    dynamicArray->show();

    return 0;
}
