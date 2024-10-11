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
    ListNode *reverse_list (ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)  {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = head;
        ListNode *end = slow;
        slow = reverse_list (slow);
        while (curr != end) {
            if (curr->val != slow->val)
                return false;
            curr = curr->next;
            slow = slow->next;
        }
        return true;
    }
};