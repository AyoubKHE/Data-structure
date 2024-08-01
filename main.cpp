#include <iostream>
#include "myLinkedList.h"

using namespace std;

int main()
{

    myLinkedList* list = new myLinkedList();
    list->push(5);
    list->push(10);
    list->push(15);
    list->push(20);
    list->show();


    return 0;
}
