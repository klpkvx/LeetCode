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
    bool solve (TreeNode *root, long long min, long long max) {
        if (!root)
            return true;
        
        if (min < root->val && root->val < max) {
            return solve (root->left, min, root->val) && solve (root->right, root->val, max);
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        return solve (root, LONG_MIN, LONG_MAX);
    }
};