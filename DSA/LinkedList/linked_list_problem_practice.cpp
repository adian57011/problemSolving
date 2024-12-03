#include<iostream>
using namespace std;

class Node{
public:
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

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head = nullptr;
    }

    void display()
    {
        Node* curr = head;

        while(curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr -> nextNode;
        }
    }
    void insert_end(int val)
    {
        Node* newNode = new Node(val);
        if(head == nullptr)
        {
            head = newNode;
            return;
        }
        else
        {
            Node* curr = head;
            while(curr->nextNode != nullptr)
            {
                curr = curr->nextNode;
            }
            curr->nextNode = newNode;
        }
    }

    int list_length()
    {
        int count = 0;
        Node* curr = head;
        while(curr != nullptr)
        {
            count++;
            curr = curr->nextNode;
        }
        return count;
    }

    int getNodeData(int pos)
    {
        if(pos < 0 || pos > this->list_length())
            return 0;
        Node* curr = head;
        int index = 0;
        while(curr != nullptr)
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

    int get_occurence(int target)
    {
        int count= 0;
        Node* curr = head;

        while(curr != nullptr)
        {
            if(target == curr->data)
            {
                count++;
            }
            curr = curr->nextNode;
        }
        return count;
    }

    void reverse_list()
    {
        Node* prev = nullptr, *curr = head, *next;

        while(curr != nullptr)
        {
            next = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

    }
};

int main()
{
    LinkedList l;
    int arr[6] = {10,20,10,40,50,60};

    for(int i = 0; i < 6; i++)
    {
        l.insert_end(arr[i]);
    }

    int len = l.list_length();

    l.display();
    cout<<endl;
    if(len % 2 == 0)
    {
        //its the even choice;
        cout << l.getNodeData((len-1)/2) << " " << l.getNodeData(len/2);
    }
    else
    {
        int target = l.getNodeData((len)/2);
        cout << target;
    }

    cout<<endl;

    cout << "Number of occurence: " << l.get_occurence(10) << endl;

    l.reverse_list();
    l.display();

    return 0;
}
