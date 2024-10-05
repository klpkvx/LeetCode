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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode *> todo;
        todo.push (root);
        vector<double> answer;
        while (!todo.empty ()) {
            int n = todo.size ();
            double avg = 0;
            for (int i = 0; i < n; i++) {
                TreeNode *root = todo.front ();
                todo.pop ();
                avg += root->val;
                if (root->left)
                    todo.push (root->left);
                if (root->right)
                    todo.push (root->right);
            }
            avg /= n;
            answer.push_back (avg);
        }
        return answer;
    }
};