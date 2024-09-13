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

 // Сбалансированное дерево - Глубина любых двух поддеревьев разлечается не более чем на 1

class Solution {
public:
    bool ans = true;
    int check_subtree (TreeNode *root){
        if (!root)
            return 0;
        if (!ans)
            return 0;
        int left = check_subtree (root->left);
        int right = check_subtree (root->right);
        if (abs (left - right) > 1)
            ans = false;
        return 1 + max(left, right);
        
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int tmp = check_subtree (root);
        return ans;
    }
};