#include <iostream>
#include "myLinkedList.h"

using namespace std;

struct book {
    string name;
    string author;
    int pages;
    double price;
};

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
