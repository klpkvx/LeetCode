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

    void solve (TreeNode *root) {
        if (!root)
            return;
        solve (root->left);
        solve (root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    TreeNode* invertTree(TreeNode* root) {
        solve (root);
        return root;
    }
};