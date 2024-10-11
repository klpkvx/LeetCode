class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size () + 1;
        int sum = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
        }
        return sz * (sz - 1) / 2 - sum;
    }
};