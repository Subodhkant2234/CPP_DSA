https://leetcode.com/problems/reverse-linked-list-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    // Step 1: Move prev to the node right before 'left'
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // The 'start' node is the first one to be reversed
    ListNode* start = prev->next;
    ListNode* then = start->next;

    // Step 2: Reverse the nodes between left and right
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}
