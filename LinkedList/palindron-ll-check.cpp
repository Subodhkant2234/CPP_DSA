//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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
    Node* findMiddle(Node *head){
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* cur){
        Node *prev = NULL;
        Node *next = NULL;
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        Node *left = head;
        Node* mid = findMiddle(head);
        Node *right = mid;
        right = reverse(mid);
        
        while(left != NULL && right != NULL){
            if(left->data != right->data)
                return false;
            left = left->next;
            right= right->next;
        }
        return true;
    }
};


//{ Driver Code Starts.

