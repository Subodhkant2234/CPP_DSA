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
    ListNode* reorder(ListNode* head) {
        // TODO: Write your code here
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* headSecondHalf = reverse(slow);  // reverse the second half
        ListNode* headFirstHalf = head;

        while (headFirstHalf != nullptr && headSecondHalf != nullptr) {
            ListNode* tmp1 = headFirstHalf->next;
            ListNode* tmp2 = headSecondHalf->next;
            headFirstHalf->next = headSecondHalf;
            headSecondHalf->next = tmp1;
            headFirstHalf = tmp1;
            headSecondHalf = tmp2;
        }
        // set the next of the last node to 'null'
        if (headFirstHalf != nullptr) {
            headFirstHalf->next = nullptr;
        }
        return head;
    }

   private:
    static ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
