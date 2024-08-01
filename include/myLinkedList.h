#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class myLinkedList
{
    private:
        node* head;

    public:
        myLinkedList() {
            this->head = NULL;
        }

        void push(int value)
        {
            node* newNode = new node;
            newNode->data = value;
            newNode->next = NULL;
            if(this->head == NULL)
            {
                this->head = newNode;
            }
            else
            {
                node* temp = this->head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void show()
        {
            node* temp = this->head;
            while(temp != NULL)
            {
                cout << temp->data << "\n";
                temp = temp->next;
            }
        }
};

#endif // MYLINKEDLIST_H
