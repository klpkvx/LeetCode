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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode *> todo;
        todo.push (root);
        vector<vector<int>> answer;
        while (!todo.empty ()) {
            int n = todo.size ();
            vector<int> els_curr_level;
            for (int i = 0; i < n; i++) {
                TreeNode *curr = todo.front ();
                todo.pop ();
                els_curr_level.push_back (curr->val);
                if (curr->left)
                    todo.push (curr->left);
                if (curr->right)
                    todo.push (curr->right);
            }
            answer.emplace_back (std::move (els_curr_level));
        }
        return answer;
    }
};