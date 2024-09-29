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
    void solve (TreeNode *root, unordered_map<int, int> &modes) {
        if (!root)
            return;
        modes[root->val]++;
        solve (root->left, modes);
        solve (root->right, modes);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> modes; // elem -> count
        solve (root, modes);
        int mx = 0;
        for (auto &[elem, count] : modes) {
            mx = max (mx, count);
        }

        vector<int> answer;
        for (auto &[elem, count] : modes) {
            if (mx == count)
                answer.push_back (elem);
        }
        return answer;
    }
};