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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> todo;
        todo.push (p);
        todo.push (q);
        while (!todo.empty ()) {
            TreeNode *q2 = todo.front ();
            todo.pop ();
            TreeNode *p2 = todo.front ();
            todo.pop ();
            if (!p2 && !q2)
                continue;
            if (!p2 || !q2)
                return false;
            if (p2->val != q2->val)
                return false;
            todo.push (p2->left);
            todo.push (q2->left);
            todo.push (p2->right);
            todo.push (q2->right);
        }
        return true;
    }
};