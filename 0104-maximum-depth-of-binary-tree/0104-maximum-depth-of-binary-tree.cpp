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
            int size = todo.size ();
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode *vertex = todo.front ();
                todo.pop ();
                if (vertex->left)
                    todo.push (vertex->left);
                if (vertex->right)
                    todo.push (vertex->right);
            }
        }
        return level;
    }
};