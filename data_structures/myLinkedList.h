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

    int length;

public:
    myLinkedList()
    {
        this->head = NULL;
        this->rear = NULL;

        this->length = 0;
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

        this->length++;
    }

    void pushFront(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = this->head;
        this->head = newNode;

        if (newNode->next == NULL)
        {
            this->rear = newNode;
        }

        this->length++;
    }

    void insertAtPosition(int value, int position)
    {

        if (position <= 0 || position > this->length + 1)
        {
            cout << "invalide position \n";
        }
        else if (position == 1)
        {
            this->pushFront(value);
        }
        else if (position == this->length + 1)
        {
            this->push(value);
        }
        else
        {
            int positionOfNodeBefore = 1;
            node *nodeBefore = this->head;

            while (position - positionOfNodeBefore != 1)
            {
                nodeBefore = nodeBefore->next;
                positionOfNodeBefore++;
            }

            node *newNode = new node;
            newNode->data = value;
            newNode->next = nodeBefore->next;
            nodeBefore->next = newNode;

            this->length++;
        }
    }

    void removeLastElement()
    {

        if (this->head == NULL)
        {
            cout << "Il n'y a aucun élément à supprimer.\n";
        }
        else
        {
            if (this->head == this->rear)
            {
                delete this->head;
                this->head = this->rear = NULL;
            }
            else
            {
                node *nodeBefore = this->head;
                while (nodeBefore->next != this->rear)
                {
                    nodeBefore = nodeBefore->next;
                }

                delete this->rear;
                this->rear = nodeBefore;
                nodeBefore->next = NULL;
            }

            this->length--;
        }
    }

    void removeFirstElement()
    {
        if (this->head == NULL)
        {
            cout << "Il n'y a aucun élément à supprimer.\n";
        }
        else
        {
            if (this->head == this->rear)
            {
                delete this->head;
                this->head = this->rear = NULL;
            }
            else
            {
                node *deletePtr = this->head;
                this->head = this->head->next;

                delete deletePtr;
                deletePtr = NULL;
            }

            this->length--;
        }
    }

    void removeAtPosition(int position)
    {
        if (position <= 0 || position > this->length)
        {
            cout << "invalide position \n";
        }
        else if (position == 1)
        {
            this->removeFirstElement();
        }
        else if (position == this->length)
        {
            this->removeLastElement();
        }
        else
        {
            int positionOfNodeBefore = 1;
            node *nodeBefore = this->head;

            while (position - positionOfNodeBefore != 1)
            {
                nodeBefore = nodeBefore->next;
                positionOfNodeBefore++;
            }

            node *deletePtr = nodeBefore->next;

            nodeBefore->next = nodeBefore->next->next;

            delete deletePtr;
            deletePtr = NULL;

            this->length--;
        }
    }

    void show()
    {
        node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }

        cout << "\n";
    }

    int getLength()
    {
        return this->length;
    }
};

#endif // MYLINKEDLIST_H
