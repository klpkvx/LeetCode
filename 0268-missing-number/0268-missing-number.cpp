class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i= 0; i < nums.size (); i++){
            sum += nums[i];
        }
        int sz = nums.size();
        return (sz * (sz + 1) >> 1) - sum;
    }
};