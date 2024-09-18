class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        if (nums[0] >= 0){
            for (int val : nums)
                answer.push_back (val * val);
            return answer;
        }
        // nums[0] < 0
        // find the first occurence positive value in nums;
        int positive_index = -1;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] >= 0) {
                positive_index = i;
                break;
            }
        }

        // all values in array are negative
        if (positive_index == -1){
            for (int i = nums.size () - 1; i >= 0; i--){
                answer.push_back (nums[i] * nums[i]);
            }
            return answer;
        }
        // negative ..... positive .... end
        int left = positive_index - 1;
        int right = positive_index;
        for (int ptr = 0; ptr < nums.size (); ptr++) {
            int value = 0;
            if (left >= 0 && right < nums.size ()) {
                if (abs (nums[left]) < nums[right]){
                    value = nums[left] * nums[left];
                    left--;
                }
                else {
                    value = nums[right] * nums[right];
                    right++;
                }
            }
            else if (left >= 0)
            {
                value = nums[left] * nums[left];
                left--;
            }
            else
            {
                value = nums[right] * nums[right];
                right++;
            }
            answer.push_back (value);
        }
        return answer;
    }
};