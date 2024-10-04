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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        ListNode *tail = curr;
        ListNode *next = nullptr;

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        tail->next = curr;
        return dummy.next;
    }
};