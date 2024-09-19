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

    void solve (TreeNode *root, int level, vector<vector<int>> &res) {        
        if (!root) return;
        if (level >= res.size ()) res.push_back ({});

        res[level].push_back (root->val);
        solve (root->left, level + 1, res);
        solve (root->right, level + 1, res);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        solve (root, 0, res);
        for (int i = 1; i < res.size (); i++) {
            if (i % 2) {
                reverse (res[i].begin (), res[i].end ());
            }
        }
        return res;
    }
};