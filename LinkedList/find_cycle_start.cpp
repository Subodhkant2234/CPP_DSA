#include <iostream>
using namespace std;

// class ListNode {
// public:
//     int val;
//     ListNode* next;

//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    // Function to find the start of the cycle in a linked list
    ListNode* findCycleStart(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using two pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Move slow pointer by 1
            fast = fast->next->next;  // Move fast pointer by 2

            if (slow == fast) {       // Cycle detected
                break;
            }
        }

        // If no cycle is found
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Step 2: Find the start of the cycle
        slow = head;                  // Reset slow to head
        while (slow != fast) {
            slow = slow->next;        // Move slow by 1
            fast = fast->next;        // Move fast by 1
        }

        // Both pointers meet at the start of the cycle
        return slow;
    }
};
