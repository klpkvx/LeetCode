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
    bool solve (TreeNode *root, long long left, long long right) {
        if (!root)
            return true;

        if (left < root->val && root->val < right) {
            return solve (root->left, left, root->val) && solve (root->right, root->val, right);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solve (root, LONG_MIN, LONG_MAX);
    }
};