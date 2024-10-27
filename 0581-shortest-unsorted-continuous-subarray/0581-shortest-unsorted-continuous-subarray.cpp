class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = - 1;
        for (int i = 0; i + 1 < nums.size (); i++) {
            if (nums[i] > nums[i + 1]) {
                left = i;
                break;
            }
        }
        int right = -1;
        for (int i = nums.size () - 1; i > 0; i--) {
            if (nums[i] < nums [i - 1]) {
                right = i;
                break;
            }
        }

        if (left == -1) 
            return 0;

        int min_i = nums[left];
        int max_i = nums[left];

        for (int i = left; i <= right; i++) {
            min_i = min (min_i, nums[i]);
            max_i = max (max_i, nums[i]);
        }
        while (left > 0 && nums[left - 1] > min_i) {
            left--;
        }
        while (right + 1 < nums.size () && nums[right + 1] < max_i) {
            right++;
        }
        return right - left + 1;
    }
};