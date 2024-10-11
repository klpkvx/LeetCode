class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size () - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right--;
            } else // nums[mid] < target
                left++;
        }
        return -1;
    }
};