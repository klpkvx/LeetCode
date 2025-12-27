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
        std::set<ListNode *> mm;
        ListNode *curr = head;
        while (curr)
        {
            if (mm.contains (curr))
            {
              return true;
            }
            mm.insert (curr);
            curr = curr->next;

        }

        return false;
    }
};