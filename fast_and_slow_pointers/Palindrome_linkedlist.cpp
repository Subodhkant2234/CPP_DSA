using namespace std;

#include <iostream>

/*class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};*/

class Solution {
public:

  ListNode *reverse(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while(curr != NULL){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  bool isPalindrome(ListNode *head) {
    // TODO: Write your code here
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode *middle = slow;
    ListNode *head1 = head;
    ListNode *headSecondHalf = reverse(middle);
    ListNode *copyheadSecondHalf = headSecondHalf;
    

    while(head1 != nullptr && headSecondHalf != nullptr){
      if(head1->val != headSecondHalf->val)
        break;
      head1 = head1->next;
      headSecondHalf = headSecondHalf->next;
    }
    reverse(copyheadSecondHalf);
    if(head1 == nullptr || headSecondHalf == nullptr)
      return true;
    else 
      return false;
  }
};
