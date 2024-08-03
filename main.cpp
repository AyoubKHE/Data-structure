#include <iostream>
#include "./data_structures/myLinkedList.h"

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

    return 0;
}
