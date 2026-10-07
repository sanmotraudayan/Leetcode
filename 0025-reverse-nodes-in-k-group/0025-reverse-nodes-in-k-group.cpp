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
     ListNode* getKthNode(ListNode* current, int k) {
        while (current != nullptr && k > 1) {
            current = current->next;
            k--;
        }

        return current;
    }

    // Reverse a detached linked list segment.
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* front = current->next;
            current->next = previous;
            previous = current;
            current = front;
        }

        return previous;
    }

public:
    // Reverse nodes of a linked list in groups of size k in-place.
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* previousLast = nullptr;

        while (temp != nullptr) {
            // Locate the kth node of the current group.
            ListNode* kthNode = getKthNode(temp, k);

            if (kthNode == nullptr) {
                if (previousLast != nullptr) {
                    previousLast->next = temp;
                }
                break;
            }

            // Store the next group head before detaching the segment.
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            // Reverse the detached group.
            reverseList(temp);

            if (temp == head) {
                head = kthNode;
            } else {
                previousLast->next = kthNode;
            }

            // Connect the reversed group tail with the next group.
            previousLast = temp;
            temp = nextNode;
        }

        return head;
        
    }
};