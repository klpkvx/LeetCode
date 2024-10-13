class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size ();
        vector<int> prefix (sz + 1, 1);
        vector<int> suffix (sz + 1, 1);
        for (int i = 1; i < sz; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int j = sz - 2; j >= 0; j--) {
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }
        vector<int> answer;
        for (int i = 0; i < sz; i++) {
            answer.push_back (suffix[i] * prefix[i]);
        }
        return answer;
    }
};