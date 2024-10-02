class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> data;
        int left = 0;
        for (int right = 0; right < nums.size (); right++) {
            if (data.contains (nums[right]))
                return true;
            data.insert (nums[right]);
            if (right - left == k) {
                data.erase (nums[left]);
                left++;
            }
        }
        return false;
    }
};