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
  bool hasCycle(ListNode *head) {
    // TODO: Write your code here
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast)
        return true;
    }
    return false;
  }
};
