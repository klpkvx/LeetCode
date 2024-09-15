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
    bool isPalindrome(ListNode* head) {
        vector<int> data;
        while (head){
            data.push_back(head->val);
            head = head->next;
        }
        for (int left = 0, right = data.size () - 1; left <= right;){
            if (data[left] == data[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};