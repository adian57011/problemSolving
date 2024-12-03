#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* nextNode;

    Node()
    {
        data = 0;
        nextNode = nullptr;
    }

    Node(int val)
    {
        data = val;
        nextNode = nullptr;
    }
};

class CircularLinkedList{
private:
    Node* tail; //for circular linked list we account for the tail rather than the head

public:

    void insert_begin(int val)
    {
        Node* newNode = new Node(val);

        if(tail == nullptr)
        {
            tail = newNode;
            tail->nextNode = tail;
        }
        else
        {
            newNode->next = tail;
            tail->nextNode = newNode;
        }
    }

    void insert_end(int val)
    {
        Node* newNode = new Node(val);

        if(tail == nullptr)
        {
            tail = newNode;
            tail->nextNode = tail;
        }
        else
        {
            tail->nextNode = newNode;
            tail = newNode;
        }
    }

    void delete_begin()
    {
        if(tail == nullptr)
        {
            return;
        }
        Node* temp = tail->nextNode;
        if(tail == tail->nextNode)
        {
            //only one node;
            tail = nullptr;
            delete temp;
        }
        else
        {
            tail->nextNode = temp->nextNode;
            delete temp;
        }
    }

};



int main()
{


    return 0;
}
