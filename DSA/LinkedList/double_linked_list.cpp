#include<iostream>
using namespace std;
//implementation of double linked list

class Node
{
public:
    int data;
    Node* nextNode;
    Node* prevNode;

    Node()
    {
        data = 0;
        nextNode = prevNode = nullptr;
    }

    Node(int val)
    {
        this->data = val;
        this->nextNode = this->prevNode = nullptr;
    }
};

class DoubleLinkedList{
private:
    Node* head;
public:
    DoubleLinkedList()
    {
        head = nullptr;
    }

    void insert_end(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* curr = head;
        while(curr->nextNode != nullptr)
        {
            curr = curr->nextNode;
        }

        curr->nextNode = newNode;
        newNode->prevNode = curr;
    }

    void insert_begin(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        head->prevNode = newNode;
        newNode->nextNode = head;
    }

    void delete_head()
    {
        if(head == NULL)
            return;

        head = head->nextNode;
        head -> prevNode = nullptr;
    }

    void delete_tail()
    {
        if(head == NULL)
            return;

        Node* curr = head;

        while(curr->nextNode != NULL)
        {
            curr = curr->nextNode;
        }
        curr->prevNode->nextNode = NULL;
        delete curr;
    }

    int get_node_data(int pos)
    {
        Node* curr = head;
        int index = 1;
        while(curr != NULL)
        {
            if(index == pos)
            {
                return curr->data;
            }
            curr = curr->nextNode;
            index++;
        }
        return 0;
    }

    void display()
    {
        Node* curr = head;

        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->nextNode;
        }
        cout<<endl;
    }

    int list_length()
    {
        Node* curr = head;
        int count = 0;

        while(curr != NULL)
        {
            count++;
            curr = curr->nextNode;
        }
        return count;
    }

    void reverse_list()
    {
        if(head == nullptr || head->nextNode == nullptr)
        {
            return;
        }

        Node* prevNode = nullptr;
        Node* currNode = head;

        while(currNode != NULL)
        {
            prevNode = currNode->prevNode;
            currNode -> nextNode = currNode->nextNode;

            currNode->nextNode = prevNode;

            currNode = currNode->prevNode;
        }
        prevNode->prevNode;
    }
};



int main()
{
    DoubleLinkedList l;
    int arr[6] = {10,20,40,50,60};

    for(int i = 0; i < 5; i++)
    {
        l.insert_end(arr[i]);
    }

    int len = l.list_length();

    l.display();
    cout << "Length of the list: " << l.list_length() <<endl;

    l.reverse_list();
    l.display();

    return 0;
}
