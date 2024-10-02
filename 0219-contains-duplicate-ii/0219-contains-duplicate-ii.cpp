class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> data;
        int left = 0;
        for (int right = 0; right < nums.size (); right++) {
            int curr_num = nums[right];
            data[curr_num]++;
            while (left < right && right - left > k) {
                int l_val = nums[left];
                if (--data[l_val] == 0)
                    data.erase (l_val);
                left++;
            }

            if (right - left <= k) {
                for (auto &[elem, count] : data) {
                    if (count > 1)
                        return true;
                }
            }
        }
        return false;
    }
};