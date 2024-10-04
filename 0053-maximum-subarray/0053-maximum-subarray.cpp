class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long mx_sum = INT_MIN;
        long long tmp = 0;
        for (int i = 0; i < nums.size (); i++) {
            tmp += nums[i];
            if (tmp > mx_sum) {
                mx_sum = tmp;
            }
            if (tmp <= 0) {
                tmp = 0;
            }
        }
        return mx_sum;
    }
};