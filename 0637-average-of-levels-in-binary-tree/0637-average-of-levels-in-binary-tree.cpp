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
    void solve (TreeNode *root, int level, unordered_map<int, vector<int>> &data) {
        if (!root)
            return;
        data[level].push_back (root->val);
        solve (root->left, level + 1, data);
        solve (root->right, level + 1, data);
    }   

    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<int, vector<int>> data; // level -> elements;
        solve (root, 0, data);
        vector<double> result (data.size ());
        for (auto &[level, values] : data) {
            double avg = 0;
            for (int i = 0; i < values.size (); i++) {
                avg += values[i];
            }
            avg /= values.size ();
            result[level] = avg;
        }
        return result;
    }
};