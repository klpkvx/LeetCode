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
    bool answer = false;
    void solve (TreeNode *root, int targetSum) {
        if (!root)
            return;

        if (!root->left && !root->right && targetSum - root->val == 0){
            answer = true;
        }

        solve (root->left, targetSum - root->val);
        solve (root->right, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        solve (root, targetSum);
        return answer;
    }
};