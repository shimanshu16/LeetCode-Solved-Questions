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

        if (!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            length++;
            tail = tail->next;
        }

        k = k % length;
        if (k == 0) return head;

        int breakPoint = length - k;
        ListNode* current = head;
        for (int i = 1; i < breakPoint; i++) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;
        tail->next = head;

        return newHead; 
    }
};