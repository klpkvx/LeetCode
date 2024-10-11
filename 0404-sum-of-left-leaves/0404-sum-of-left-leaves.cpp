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
    int solve (TreeNode *root, int is_left) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            return is_left ? root->val : 0;
        }
        return solve (root->left, true) + solve (root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        return solve (root->left, true) + solve (root->right, false);
    }
};