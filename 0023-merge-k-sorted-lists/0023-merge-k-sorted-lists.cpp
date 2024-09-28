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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size (); i++) {
            ListNode *head = lists[i];
            while (head) {
                pq.push (head->val);
                head = head->next;
            }
        }

        ListNode dummy;
        ListNode *head = &dummy;
        while (!pq.empty ()) {
            int val = pq.top ();
            head->next = new ListNode (val);
            head = head->next;
            pq.pop ();
        }
        return dummy.next;
    }
};