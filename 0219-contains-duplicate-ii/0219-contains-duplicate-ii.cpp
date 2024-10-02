class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> data; // elem -> index;
        for (int i = 0; i < nums.size (); i++) {
            int curr = nums[i];
            if (data.contains (curr) && abs (data[curr] - i) <= k)
                return true;
            data[curr] = i;
        }
        return false;
    }
};