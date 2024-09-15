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
    void solve (TreeNode *root, int &sum, int is_left){
        if (!root)
            return;

        if (!root->left && !root->right && is_left){
            sum += root->val;
            return;
        }

        solve (root->left, sum, true);
        solve (root->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve (root->left, sum, true);
        solve (root->right, sum, false);
        return sum;
    }
};