class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate (nums.begin (), nums.end(), 0);
        int all = 0;
        for (int i = 0; i < nums.size () + 1; i++) {
            all += i;
        }
        return all - sum;
    }
};