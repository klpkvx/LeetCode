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
    bool ans = false;
    void solve (TreeNode *root, int targetsum){
        if (!root)
            return;
        if (!root->left && !root->right && root->val == targetsum)
        {
            ans = true;
            return;
        }

        solve (root->left, targetsum - root->val);
        solve (root->right, targetsum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        solve (root, targetSum);
        return ans;
    }
};