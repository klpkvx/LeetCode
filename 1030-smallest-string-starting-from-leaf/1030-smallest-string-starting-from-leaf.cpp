/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string curr;
    void solve (TreeNode *root, string &answer) {
        if (!root)
            return;
        answer += char(root->val + 'a');
        if (!root->left && !root->right) {
            reverse (answer.begin (), answer.end ());
            if (curr.empty () || answer < curr)
                curr = answer;
            reverse (answer.begin (), answer.end ());
        }
        solve (root->left, answer);
        solve (root->right, answer);
        answer.pop_back ();
    }
    string smallestFromLeaf(TreeNode* root) {
        string answer;
        solve (root, answer);
        return curr;
    }
};