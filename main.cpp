#include <iostream>
#include "./include/myLinkedList.h"

using namespace std;

int main()
{

    myLinkedList* list = new myLinkedList();
    
    list->pushFront(1);
    list->pushFront(2);
    list->push(3);

    list->show();

    


    return 0;
}
