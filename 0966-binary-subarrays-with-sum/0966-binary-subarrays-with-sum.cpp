class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> data = {{0, 1}}; // pref_sum -> count
        int answer = 0;
        int prefsum = 0;
        for (int i = 0; i < nums.size (); i++) {
            prefsum += nums[i];
            if (data.contains (prefsum - goal)) {
                answer += data[prefsum - goal];
            }
            data[prefsum]++;
        }
        return answer;
    }
};