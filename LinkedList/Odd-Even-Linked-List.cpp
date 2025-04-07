/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

/*
   ListNode* oddEvenList(ListNode* head) {
        // If the list is empty, just return an empty list
        if (!head) {
            return nullptr;
        }

        // Use 'oddTail' to keep track of the last node in the odd-indexed nodes
        ListNode* oddTail = head;
        // Use 'evenHead' and 'evenTail' to keep track of the even-indexed nodes
        ListNode *evenHead = head->next, *evenTail = evenHead;
        // Iterate as long as there are even nodes to process
        while (evenTail && evenTail->next) {
            // Connect the odd nodes
            oddTail->next = evenTail->next;
            oddTail = oddTail->next;

            // Connect the even nodes
            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }
        // Attach the even nodes to the end of the odd nodes
        oddTail->next = evenHead;

        // Return the reorganized list
        return head;
    }
    */
