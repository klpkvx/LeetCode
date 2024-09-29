class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        int start = 0;
        int min = INT_MAX;
        for (int i = 0; i < nums.size (); i++) {
            int curr = nums[i];
            if (abs (curr) < min) {
                min = abs(curr);
                start = i;
            }
        }
        answer.push_back (min * min);
        int left = start - 1;
        int right = start + 1;
        while (left >= 0 && right < nums.size ()) {
            int l_val = nums[left] * nums[left];
            int r_val = nums[right] * nums[right];
            if (l_val < r_val) {
                answer.push_back (l_val);
                left--;
            } else {
                answer.push_back (r_val);
                right++;
            }
        }

        while (left >= 0) {
            answer.push_back (nums[left] * nums[left]);
            left--;
        }
        while (right < nums.size ()) {
            answer.push_back (nums[right] * nums[right]);
            right++;
        }
        return answer;
    }
};