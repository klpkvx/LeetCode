class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size ();
        if (k == 0)
            return;
        vector<int> copy (nums);
        for (int i = 0; i < nums.size (); i++) {
            nums[ (i + k) % nums.size ()] = copy[i]; 
        }
    }
};