/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool is_valid (TreeNode *root, long long left, long long right) {
        if (!root) {
            return true;
        }

        if (left < root->val && root->val < right) { 
            return is_valid (root->left, left, root->val) && is_valid (root->right, root->val, right);
        }

        else return false;
    }

    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return is_valid (root, min, max);
        }
};