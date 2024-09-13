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

    void solve (TreeNode *root, vector<int> &path, vector<string> &answer){
        if (!root)
            return;
        path.push_back (root->val);
        if (!root->left && !root->right){
            // build_answer;
            string ans;
            for (int i = 0; i < path.size (); i++){
                ans += to_string (path[i]);
                if (i != path.size () - 1)
                    ans += "->";
            }
            answer.push_back (ans);
        }
        solve (root->left, path, answer);
        solve (root->right, path, answer);
        path.pop_back ();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        vector<int> path;
        solve (root, path, answer);
        return answer;
    }
};