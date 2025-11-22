https://www.propeers.in/roadmaps/686f517e881b549d7cd72269/reverse-nodes-in-k-group?todoItemId=686f790f63468d67c4e0d925
// Note : -
// - Modify the function or parameters if needed.
// - Signatures function may vary, adjust parameters if required.

class Solution {
public:
   ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Count the total number of nodes
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        while (count >= k) {
            ListNode* current = prev->next;
            ListNode* next_node = current->next;
            for (int i = 1; i < k; i++) {
                current->next = next_node->next;
                next_node->next = prev->next;
                prev->next = next_node;
                next_node = current->next;
            }
            prev = current;
            count -= k;
        }
        return dummy.next;
    }
};
