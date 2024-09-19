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
    bool is_valid (TreeNode *root, long long left, long long right) {
        if (!root)
            return true;

        if (root->val < right && root->val > left) {
            return is_valid (root->left, left, root->val) && is_valid (root->right, root->val, right);
        }
        return false;

    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        return is_valid (root, LONG_MIN, LONG_MAX);
        }
};