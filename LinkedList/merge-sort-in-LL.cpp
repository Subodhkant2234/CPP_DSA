//{ Driver Code Starts
// Initial Template for C++
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
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* first, Node* second){
        // If either list is empty, return the other list
        if (first == nullptr) return second;
        if (second == nullptr) return first;
        
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        
        while(first != nullptr && second != nullptr){
            if(first->data < second->data){
                cur->next = first;
                first = first->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }
        if(first != nullptr){
            cur->next = first;
        } else {
            cur->next = second;
        }
        return dummy->next;
    }
    
    Node* split (Node* ptr) {
        Node *fast = ptr;
        Node *slow = ptr;
        while(fast != nullptr && fast->next != nullptr){
//          slow = slow->next;
            fast = fast->next->next;
            if (fast != nullptr) {
                slow = slow->next;
            }
        }
        Node* middle = slow->next;
        slow->next = nullptr;
        return middle;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == nullptr || head->next == nullptr)
            return head;
            
        Node *first =  head;
        Node *second = split(head);
        Node* first_half = mergeSort(first);
        Node* second_half = mergeSort(second);
        return merge(first_half, second_half);
  
    }
};

