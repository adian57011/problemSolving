#include<iostream>
using namespace std;

//Time to build the linked list by myself//

//First of all i need to make a node class

class Node{
//this node class will have two attributes. one will be the data part. other will be pointer to the next node

public:
    int value;
    Node* nextNode;

    Node()
    {
        value = 0;
        nextNode = NULL;
    }

    Node(int value)
    {
        this->value = value;
        nextNode = nullptr;
    }
};
//with this the node class is completed. now I need to build a LinkedList class

class LinkedList{
public:
    Node* head;

    LinkedList()
    {
        head = nullptr; //this needs to empty as we did not enter anything into the linked list.
    }

    void insert_end(int value)
    {
        //while inserting at end. need to account 3 things.
        //1. Initiate a node with the value.
        //2. if the linked list is empty then it will the head.
        //3. if the linked list is not empty then it will search until nextNode is found null. at insert itself there.

        //Initiating new node:

        Node* newNode = new Node(value);

        //if the linked list is empty then it is the single value of the list.
        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr -> nextNode != nullptr)
        {
            curr = curr->nextNode;
        }
        curr->nextNode = newNode;
    }

    void insert_begin(int value)
    {
        Node* newNode = new Node(value);
        newNode->nextNode = head;
        head = newNode;
    }

    void traverse()
    {
        Node* curr = head;
        while(curr != nullptr)
        {
            cout<< curr->value << " ";
            curr = curr->nextNode;
        }
    }

    bool search_list(int target)
    {
        Node* curr = head;
        while( curr != nullptr)
        {
            if(curr -> value == target)
            {
                return true;
            }
            curr = curr->nextNode;
        }
        return false;
    }

    int length_list()
    {
        Node* curr = head;
        int length = 0;

        while(curr != nullptr)
        {
            length++;
            curr = curr->nextNode;
        }
        return length;
    }

    void insert_middle(int pos,int value)
    {
        int length = this -> length_list();
        if(pos == length)
        {
            this->insert_end(value);
            return;
        }
        if(pos == 1)
        {
            this->insert_begin(value);
            return;
        }

        //if insert in the middle. then need to get the previous node.also
        Node* prev = head;
        int count = 1;
        while(count < pos-1 && prev != nullptr)
        {
            prev = prev->nextNode;
            count++;
        }

        Node* temp = new Node(value);
        temp->nextNode = prev->nextNode;
        prev->nextNode = temp;
    }
};

int main()
{
    LinkedList l;

    l.insert_end(10);
    l.insert_end(20);
    l.insert_end(30);

    l.insert_begin(6);
    l.insert_middle(3,15);
    l.insert_middle(1,5);

    l.traverse();

    return 0;
}
