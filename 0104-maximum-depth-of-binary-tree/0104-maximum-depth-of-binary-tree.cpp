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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode *> todo;
        todo.push (root);
        int level = 0;
        while (!todo.empty ()) {
            int n = todo.size ();
            level++;
            for (int i = 0; i < n; i++) {
                TreeNode *curr = todo.front ();
                todo.pop ();
                if (curr->left)
                    todo.push (curr->left);
                if (curr->right)
                    todo.push (curr->right);
            }
        }
        return level;
    }
};