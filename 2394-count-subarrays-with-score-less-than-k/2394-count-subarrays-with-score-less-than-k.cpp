class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        long long score = 0;
        long long count = 0;
        for (int right = 0; right < nums.size (); right++) {
            score += nums[right];
            while (score * (right - left + 1)>= k){
                score -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};