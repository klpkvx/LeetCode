class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> mm;
        for (int i = 0; i < nums.size (); i++)
        {
            if (mm.contains (target - nums[i]))
                return {i, mm[target-nums[i]]};
            else
                mm[nums[i]] = i;         
        }
        return {};
    }
};