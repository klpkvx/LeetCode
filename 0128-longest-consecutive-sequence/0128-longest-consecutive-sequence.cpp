class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty ())
            return 0;

        unordered_set<int> values;
        int max_val = 1;
        for (int i : nums) {
            values.insert (i);
        }

        for (int num : nums) {
            if (values.find (num - 1) != values.end ())
                continue;
            int curr_num = num;
            int len = 1;
            while (values.find (num + 1) != values.end ()) {
                num++;
                len++;
            }
            max_val = max (max_val, len);
        }

       return max_val;
    }
};