/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve (TreeNode *root, long long left_value, long long right_value) {
        if (!root)
            return true;

        if (left_value < root->val && root->val < right_value) {
            return solve (root->left, left_value, root->val) && solve (root->right, root->val, right_value);
        }
        
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solve (root, LONG_MIN, LONG_MAX);
    }
};