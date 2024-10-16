class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int count = INT_MAX;
        int sum = 0;
        for (int i = 0;  i < nums.size (); i++) {
            sum += nums[i];
            count = min (count, sum);
        }
        if (count >= 1)
            return 1;
        else
            return 1 - count;

    }
};