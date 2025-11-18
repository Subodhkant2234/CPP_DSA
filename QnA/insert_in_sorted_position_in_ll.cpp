#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node in sorted order
void insertSorted(Node*& head, int value) {
    Node* newNode = new Node(value);

    // Case 1: Empty list or value should be inserted at the head
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Find the position to insert
    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    Node* head = nullptr;

    insertSorted(head, 10);
    insertSorted(head, 5);
    insertSorted(head, 15);
    insertSorted(head, 12);

    printList(head);  // Output: 5 -> 10 -> 12 -> 15 -> NULL

    return 0;
}
