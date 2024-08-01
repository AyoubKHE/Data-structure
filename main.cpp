#include <iostream>
#include "./include/myLinkedList.h"

using namespace std;

int main()
{

    myLinkedList* list = new myLinkedList();
    list->push(5);
    list->push(10);
    list->push(15);
    list->push(20);
    list->show();

    // cout << "hello world";


    return 0;
}
