#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class myLinkedList
{
private:
    node *head;
    node *rear;

public:
    myLinkedList()
    {
        this->head = NULL;
        this->rear = NULL;
    }

    void push(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;

        if (this->head == NULL)
        {
            this->head = newNode;
            this->rear = newNode;
        }
        else
        {
            this->rear->next = newNode;
            this->rear = newNode;
        }
    }

    void pushFront(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = this->head;
        this->head = newNode;
    }

    void show()
    {
        node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
};

#endif // MYLINKEDLIST_H
