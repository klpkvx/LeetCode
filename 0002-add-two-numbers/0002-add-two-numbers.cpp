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

 // 13
 // 10
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *head = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            val += carry;
            carry = val / 10;
            ListNode *new_node = new ListNode (val % 10);
            head->next = new_node;
            head = head->next;
        }

        return dummy.next;
    }
};