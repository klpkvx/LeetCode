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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;
        ListNode dummy;
        dummy.next = head;
        ListNode *slow =  &dummy;
        ListNode *curr = head;
        while (curr) {
            if (curr->val == val) {
                slow->next = curr->next;
                curr = curr->next;
            } else {
                slow = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};