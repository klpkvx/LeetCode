class Solution {
public:

// 3 1 -2 -5 2 -4
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer (nums.size ());
        int negative = 1, positive = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] > 0) {
                answer[positive] = nums[i];
                positive += 2;
            } else {
                answer[negative] = nums[i];
                negative+=2;
            }
        }
        return answer;
    }
};