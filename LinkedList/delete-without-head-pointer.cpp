//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list node structure */
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} * head;

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        // Your code here
        Node *tmp = del_node->next;
        if(tmp != NULL){
            del_node->data = tmp->data;
            del_node->next = tmp->next;
            delete[] tmp;
        }
    }
};

