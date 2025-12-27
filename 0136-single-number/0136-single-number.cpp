class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> mm; // num -> count
        for (const int n : nums)
        {
            mm[n]++;
        }
        for (const auto &[k, v] : mm)
        if (v == 1)
          return k;
        return -1;
    }
};