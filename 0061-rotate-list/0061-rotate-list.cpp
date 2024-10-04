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

    ListNode *rotate (ListNode *head) {
        ListNode dummy;
        ListNode *curr = head;
        ListNode *prev = &dummy;
        while (curr) {
            if (!curr->next) {
                prev->next = nullptr;
                curr->next = head;
                return curr;
            }
            prev = curr;
            curr = curr->next;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return {};

        ListNode *tmp = head;
        int len = 0;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }

        for (int i = 0; i < k % len; i++) {
            head = rotate (head);
        }
        return head;
    }
};