class Solution {
public:

// 1 3 5 6 | target = 2
// left = 0, right = 3. mid = 3 / 2 = 1; 3 > 2 right = 0;
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size () - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right  = mid - 1;
            } else if (nums[mid] == target)
                return mid;
        }
        return left;
    }
};