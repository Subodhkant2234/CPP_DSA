//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    Node* intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        
        while(ptr1 != ptr2){
            if(ptr1){
                ptr1 = ptr1->next;
            } else{
                ptr1 = head2;
            }
            
            if(ptr2){
                ptr2 = ptr2->next;
            } else {
                ptr2 = head1;
            }
        }
        return ptr1;
        
    }
};

