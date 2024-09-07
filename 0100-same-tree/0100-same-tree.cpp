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

    bool solve (TreeNode *p_sub, TreeNode *q_sub)
    {
        if (!p_sub && !q_sub)
            return true;
        if (p_sub && !q_sub || !p_sub && q_sub)
            return false;

        if (p_sub->val == q_sub->val)
        {   
            bool result = true;
            result &= solve (p_sub->left, q_sub->left);
            result &= solve (p_sub->right, q_sub->right);
            return result;
        }
        else
            return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve (p, q);
    }
};