/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curr = head;
        if (!curr)
            return false;
        
        if (!curr->next)
            return false;
        
        ListNode *fast = curr->next;

        if (curr == fast)
            return true;
        
        while (curr && fast && fast->next)
        {
            curr = curr->next;
            fast = fast->next->next;
            if (curr == fast)
                return true;
        }


        return false;     
    }
};