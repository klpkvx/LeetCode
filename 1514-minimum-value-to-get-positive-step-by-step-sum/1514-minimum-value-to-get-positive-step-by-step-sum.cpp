class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_value = 0;
        int count = INT_MAX;
        vector<int> pref_sum (nums.size () + 1, 0);
        for (int i = 1;  i < pref_sum.size (); i++) {
            pref_sum[i] = pref_sum[i - 1] + nums[i - 1];
            count = min (count, pref_sum[i]);
        }
        if (count >= 1)
            return 1;
        else
            return 1 - count;

    }
};