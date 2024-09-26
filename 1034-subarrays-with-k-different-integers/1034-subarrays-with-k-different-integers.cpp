class Solution {
public:

    int solve (vector<int> &nums, int k) {
        unordered_map<int, int> data; // nums[i] -> count
        int left = 0;
        int count = 0;
        for (int right = 0; right < nums.size (); right++) {
            data[nums[right]]++;
            while (left < nums.size () && data.size () > k) {
                data[nums[left]]--;
                if (data[nums[left]] == 0) { 
                    data.erase (nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve (nums, k) - solve (nums, k - 1);
    }
};