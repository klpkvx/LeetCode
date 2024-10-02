class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data; // nums[i] -> index
        for (int i = 0; i < nums.size (); i++) {
            int look_for_val = target - nums[i];
            if (data.contains (look_for_val)) {
                return {data[look_for_val], i};
            }
            data[nums[i]] = i;
        }
        return {};
    }
};