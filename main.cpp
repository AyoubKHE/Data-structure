#include <iostream>
#include "./include/myLinkedList.h"

using namespace std;

int main()
{

    myLinkedList *list = new myLinkedList();

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);

    list->insertAtPosition(99, 3);

    list->show();

    return 0;
}
