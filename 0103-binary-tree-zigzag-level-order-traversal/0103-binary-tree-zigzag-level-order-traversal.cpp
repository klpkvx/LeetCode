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
        queue<TreeNode *> todo;
        if (!root)
            return {};
        todo.push (root);
        int count = 1;
        vector<vector<int>> answer;
        while (!todo.empty ()) {
            int sz = todo.size ();
            vector<int> data (sz);
            count++;
            for (int i = 0; i < sz; i++) {
                TreeNode *curr = todo.front ();
                todo.pop ();
                int index = count % 2 == 0 ? i : sz - 1 - i;
                data[index] = curr->val;
                if (curr->left)
                    todo.push (curr->left);
                if (curr->right)
                    todo.push (curr->right);
            }
            answer.push_back (data);
        }
        return answer;
    }
};