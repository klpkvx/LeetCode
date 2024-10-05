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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode *> todo;
        todo.push (root);
        vector<vector<int>> answer;
        int index = 0;
        while (!todo.empty ()) {
            int n = todo.size ();
            vector<int> tmp (n);
            for (int i = 0; i < n; i++) {
                TreeNode *root = todo.front ();
                todo.pop ();
                int ind = index % 2 == 0 ? i : n - 1 - i;
                tmp[ind] = root->val;
                if (root->left)
                    todo.push (root->left);
                if (root->right)
                    todo.push (root->right);
            }
            index++;
            answer.emplace_back (std::move(tmp));
        }
        return answer;
    }
};