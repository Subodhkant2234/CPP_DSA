//{ Driver Code Starts
// Initial Template for C++
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* cur = head;
        Node* prev= nullptr;
        Node* next= nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

