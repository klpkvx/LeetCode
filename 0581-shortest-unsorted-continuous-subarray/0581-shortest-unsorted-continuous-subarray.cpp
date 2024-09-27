class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, right = -1;
        for (int i = 0; i + 1 < nums.size (); i++) {
            if (nums[i] > nums[i + 1]) {
                left = i;
                break;
            }
        }

        for (int i = nums.size () - 1; i >= 1; i--) {
            if (nums[i] < nums[i - 1]) {
                right = i;
                break;
            }
        }

        if (left == -1) return 0;
        int min_i = nums[left], max_i = nums[left];
        for (int i = left; i <= right; i++) {
            min_i = min (min_i, nums[i]);
            max_i = max (max_i, nums[i]);
        }
        left = upper_bound (nums.begin (), nums.begin () + left, min_i) - nums.begin ();
        right = lower_bound (nums.begin () + right + 1, nums.end (), max_i) - nums.begin ();
        return right - left;
    }
};