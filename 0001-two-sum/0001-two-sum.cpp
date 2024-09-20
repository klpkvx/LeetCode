class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data; // nums[i] -> i
        for (int i = 0; i < nums.size (); i++) { 
                if (!data.contains (target - nums[i]))
                    data[nums[i]] = i;
                else
                    return {data[target - nums[i]], i};
        }
        return {};
    }
};