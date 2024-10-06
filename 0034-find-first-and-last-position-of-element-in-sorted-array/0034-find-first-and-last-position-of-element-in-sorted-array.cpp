class Solution {
public:

    int lower_bound (vector<int> &nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound (nums, 0, nums.size () - 1, target);
        int end = lower_bound (nums, 0, nums.size () - 1, target + 1) - 1;
        if (start < nums.size () && nums[start] == target && nums[end] == target)
            return {start, end};
        return {-1, -1};
    }
};