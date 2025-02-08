//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy = new Node(-1);
        Node* result = dummy;
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                result->next = head1;
                head1 = head1->next;
            } else {
                result->next = head2;
                head2 = head2->next;
            }
            result = result->next;
        }
        if(head1!= NULL){
            result->next = head1;
        } else {
            result->next = head2;
        }
        return dummy->next;
    }
};
