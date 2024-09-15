class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int all_sum = 0;
        for (int i= 0; i < nums.size (); i++){
            all_sum += (i + 1) - nums[i];
        }
        int sz = nums.size();
        return all_sum;
    }
};