class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> T (nums.size (), 1);
        for (int i = 1; i < nums.size (); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    T[i] = max (T[i], T[j] + 1);
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < T.size (); i++)
            mx = max (mx, T[i]);
        return mx;
    }
};