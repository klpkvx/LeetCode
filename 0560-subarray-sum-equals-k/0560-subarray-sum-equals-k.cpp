class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> data = {{0, 1}}; // prefsum -> count
        int prefsum = 0;
        int count = 0;
        for (int i = 0; i < nums.size (); i++) {
            prefsum += nums[i];
            if (data.contains (prefsum - k)) {
                count += data[prefsum - k];
                
            } 
            data[prefsum]++;
        }
        return count;
    }
};