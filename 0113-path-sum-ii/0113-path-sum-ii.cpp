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

    void solve (TreeNode *root, int target_sum, vector<int> &path, vector<vector<int>> &answer){
        if (!root)
            return;

        path.push_back (root->val);

        if (!root->left && !root->right && root->val == target_sum)
            answer.push_back (path);
        solve (root->left, target_sum - root->val, path, answer);
        solve (root->right, target_sum - root->val, path, answer);

        path.pop_back ();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> path;
        solve (root, targetSum, path, answer);
        return answer;
    }
};