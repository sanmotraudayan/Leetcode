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
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle empty list, single node, or zero rotations
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
 
        int length = 1;
        ListNode* tail = head;
 
        // Locate the tail node while calculating list length
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }
 
        // Skip redundant complete rotation cycles
        k = k % length;
        if (k == 0) {
            return head;
        }
 
        // Link tail to head to form a temporary circle
        tail->next = head;
 
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
 
        // Traverse to locate the node that will serve as the new tail
        for (int step = 0; step < stepsToNewTail; step++) {
            newTail = newTail->next;
        }
 
        // Pinpoint the new head node next to the new tail
        ListNode* newHead = newTail->next;
 
        // Break the circular reference to restore linear list structure
        newTail->next = nullptr;
 
        return newHead;
    }
};