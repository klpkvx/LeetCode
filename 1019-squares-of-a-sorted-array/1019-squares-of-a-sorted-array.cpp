class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer (nums.size ());
        int left = 0;
        int right = nums.size () -1;
        int ptr = answer.size () - 1;
        while (left <= right) {
            int l = nums[left];
            int r = nums[right];
            int res = 0;
            if (abs (l) > abs (r)){
                left++;
                res = l;
            } else {
                right--;
                res = r;
            }
            answer[ptr--] = res*res;
        }
        return answer;
    }
};