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
    ListNode* partition(ListNode* head, int x) {
        ListNode low_head;
        ListNode high_head;
        ListNode *low = &low_head;
        ListNode *high = &high_head;
        while (head) {
            if (head->val < x) {
                low->next = head;
                low = low->next;
            } else {
                high->next = head;
                high = high->next;
            }
            head = head->next;
        }
        high->next = nullptr;
        low->next = high_head.next;
        return low_head.next;
    }
};