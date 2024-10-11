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
    int answer = 0;    
    void solve (TreeNode *root, bool is_left) {
        if (!root)
            return;
        if (is_left && !root->left && !root->right)
            answer += root->val;
        solve (root->left, true);
        solve (root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        solve (root->left, true);
        solve (root->right, false);
        return answer;
    }
};