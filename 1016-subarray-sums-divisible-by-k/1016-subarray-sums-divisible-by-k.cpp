class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        if (nums.empty ())
            return 0;
        unordered_map<int,int> sums = {{0, 1}}; // index -> count;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
            int res = sum % k;
            if (res < 0) res += k;
            if (sums.find (res) != sums.end ())
                count += sums[res];
            sums[res]++;
        }
        return count;
    }
};