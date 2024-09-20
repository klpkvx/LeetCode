class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size () - 1;
        while (left < right) { 
            if (nums[left] < target - nums[right]) {
                left++;
            } else if (nums[left] > target - nums[right]) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};