class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> data = {{0, 1}}; // sum -> 
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
            auto it = data.find (sum - goal);
            if (it != data.end ()) {
                count += it->second;
            }
            data[sum]++;
        }
        return count;
    }
};