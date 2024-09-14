class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data; // nums[i] -> index
        for (int i = 0; i < nums.size (); i++){
            if (data.contains (target - nums[i])){
                return {i, data[target - nums[i]]};
            }
            else
                data[nums[i]] = i;
        }
        return {7, 7};
    }
};