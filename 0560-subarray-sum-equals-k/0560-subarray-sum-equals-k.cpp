class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> data {{0, 1}}; // sum -> index
        int total = 0;
        int count = 0;
        for (int i = 0; i < nums.size (); i++) {
            total += nums[i];
            auto it = data.find (total - k);
            if (it != data.end ()) {
                count += it->second;
            }

            if (auto it = data.find (total) != data.end ()){
                data[total]++;
            } else 
                data[total] = 1;
        }
        return count;
    }
};