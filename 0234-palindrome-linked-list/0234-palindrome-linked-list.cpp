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
    ListNode *reverse_list (ListNode *head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr){
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
        while (fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }

        ListNode *reversed_part = reverse_list (slow);
        while (reversed_part && head){
            if (reversed_part->val != head->val)
                return false;
            reversed_part = reversed_part->next;
            head = head->next;
        }
        return true;
    }
};