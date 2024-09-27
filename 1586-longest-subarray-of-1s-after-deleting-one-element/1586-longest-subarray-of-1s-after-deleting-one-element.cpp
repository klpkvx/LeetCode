class Solution {
public:
// 0 1 1 1 0 1 1 0 1
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int i = 0;
        int j = 0;
        for (j = 0; j < nums.size (); j++) {
            if (nums[j] == 0) k--;
            if (k < 0 && nums[i++] == 0) k++;
        }
        return j - i - 1;
    }
};