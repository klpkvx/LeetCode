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
        if (!head || k == 0 | !head->next) return head;
        int len = 1;
        ListNode *curr = head;
        while (curr->next) {
            len++;
            curr = curr->next;
        }
        if (k % len == 0)
            return head;
        k = len - k % len;
        curr->next = head;
        while (k--) 
            curr = curr->next;
        ListNode *tmp = curr->next;
        curr->next = nullptr;
        return tmp;
    }
};