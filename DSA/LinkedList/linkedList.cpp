#include <iostream>
using namespace std;

// Implementation of linked list with basic operations
class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    LinkedList()
    {
        Node* head = new Node();
    }
    Node* insert_beginning(Node* head, int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* insert_ending(Node*& head, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return head;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode; // Link the new node at the end
        return head;
    }

    void display(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList l;
    Node* head = nullptr;

    l.insert_ending(head,10);
    l.insert_ending(head,20);
    l.insert_ending(head,30);
    l.insert_ending(head,40);

    // Display the linked list
    l.display(head);

    return 0;
}
