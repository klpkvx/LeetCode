class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int tmp_sum = 0;
        for (int i = 0; i < nums.size (); i++) {
            tmp_sum += nums[i];
            if (tmp_sum > max_sum){
                max_sum = tmp_sum;
            }
            if (tmp_sum < 0) {
                tmp_sum = 0;
            }
        }
        return max_sum;
    }
};