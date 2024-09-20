/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr)
            return root;
        TreeNode *lowest_left_ancestor = lowestCommonAncestor (root->left, p, q);
        TreeNode *lowest_right_ancestor = lowestCommonAncestor (root->right, p, q);
        if (lowest_left_ancestor && lowest_right_ancestor) {
            return root;
        } else {
            return lowest_left_ancestor ? lowest_left_ancestor : lowest_right_ancestor;
        }
        return root;
    }
};