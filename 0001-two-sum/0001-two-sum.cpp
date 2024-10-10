class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table; // nums[i] -> index
        for (int i = 0; i < nums.size (); i++) {
            int elem_to_search = target - nums[i];
            if (table.contains (elem_to_search)) {
                return {table[elem_to_search], i};
            }
            table[nums[i]] = i;
        }
        return {};
    }
};