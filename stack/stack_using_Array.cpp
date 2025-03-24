// C++ program to create a stack with
// given capacity
#include <bits/stdc++.h>
using namespace std; 

class Stack { 
    int top, cap; 
    int *a; 

public: 
    Stack(int cap) { 
        this->cap = cap; 
        top = -1; 
        a = new int[cap]; 
    } 

    ~Stack() { 
        delete[] a; 
    } 

    bool push(int x) { 
        if (top >= cap - 1) { 
            cout << "Stack Overflow\n"; 
            return false; 
        } 
        a[++top] = x; 
        return true; 
    } 

    int pop() { 
        if (top < 0) { 
            cout << "Stack Underflow\n"; 
            return 0; 
        } 
        return a[top--]; 
    } 

    int peek() { 
        if (top < 0) { 
            cout << "Stack is Empty\n"; 
            return 0; 
        } 
        return a[top]; 
    } 

    bool isEmpty() { 
        return top < 0; 
    } 
}; 
