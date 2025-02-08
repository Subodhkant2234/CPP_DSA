//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node* fast = head;
        Node* slow = head;
        while(k > 0 && fast != NULL){
            fast = fast->next;
            k--;
        }
        
        if(k > 0) return -1;
        
        while(fast != NULL && slow != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }
};

