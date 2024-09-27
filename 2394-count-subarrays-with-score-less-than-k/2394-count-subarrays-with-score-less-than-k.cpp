class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long left = 0;
        long long count = 0;
        for (long long right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (left < nums.size () && sum * (right - left + 1) >= k) {
                sum -=nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};