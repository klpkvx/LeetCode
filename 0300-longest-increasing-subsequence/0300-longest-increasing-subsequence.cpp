class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> T (nums.size (), 1);
        for (int i = 1; i < nums.size (); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    T[i] = max (T[i], T[j] + 1);
                }
            }
        }
        int max = 0;
        for (int i = 0; i < T.size (); i++) {
            if (T[i] > max) {
                max = T[i];
            }
        }
        return max;
    }
};