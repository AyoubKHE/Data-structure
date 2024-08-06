#include <iostream>
#include "./data_structures/myLinkedList.h"
#include "./data_structures/myDynamicArray.h"

using namespace std;

int main()
{

    myLinkedList *list = new myLinkedList();

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->push(5);

    list->removeAtPosition(3);

    list->show();
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, INT_MIN, 9, 10};

    myDynamicArray *dynamicArray = new myDynamicArray(arr);

    dynamicArray->removeAtPosition(3);

    dynamicArray->show();

    return 0;
}
