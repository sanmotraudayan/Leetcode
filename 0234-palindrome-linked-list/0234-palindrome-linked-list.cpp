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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* front = temp->next;  // save next node
            temp->next = prev;            // reverse the link
            prev = temp;                  // move prev forward
            temp = front;                  // move curr forward
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode* newhead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;
        while(second!=NULL){
            if(first->val != second->val){
                reverseList(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseList(newhead);
        return true;
    }
};