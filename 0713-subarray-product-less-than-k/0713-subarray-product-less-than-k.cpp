class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int left = 0;
        int prod = 1;
        int res = 0;
        for (int right = 0; right < nums.size (); right++) {
            prod *= nums[right];
            while (prod >= k)  {
                prod /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};