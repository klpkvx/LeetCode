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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        stack<TreeNode *> st;
        if (root->left) {
            if (!root->right)
                return false;
            st.push (root->left);
            st.push (root->right);
        } else if (root->right)
            return false;

        while (!st.empty ()) {
            if (st.size () % 2 != 0)
                return false;
            TreeNode *right = st.top ();
            st.pop ();
            TreeNode *left = st.top ();
            st.pop ();
            if (right->val != left->val)
                return false;

            if (left->left) {
                if (!right->right) 
                    return false;
                st.push (left->left);
                st.push (right->right);
            } else if (right->right)
                return false;

            if (left->right) {
                if (!right->left)
                    return false;
                st.push (left->right);
                st.push (right->left);
            } else if (right->left)
                return false;
        }
        return true;
    }
};