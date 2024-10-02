class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty ())
            return 0;
        sort(nums.begin (), nums.end ());
        int max_val = INT_MIN;
        int count = 1;
        for (int i = 1; i < nums.size (); i++) {
            while (i < nums.size () && nums[i] == nums[i - 1])
                i++;
            if (i < nums.size () && nums[i] - nums[i - 1] == 1) {
                max_val = max (max_val, count);
                count++;
            } else {
                count = 1;
            }
        }
        return max_val == INT_MIN ? 1 : max_val + 1;
    }
};