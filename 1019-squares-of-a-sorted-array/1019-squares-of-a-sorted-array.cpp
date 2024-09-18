class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size () - 1;
        int i = nums.size () - 1;
        vector<int> answer (nums.size (), 0);
        while (left <= right) {
            int l_val = nums[left] * nums[left];
            int r_val = nums[right] * nums[right];
            if (r_val > l_val){
                answer[i] = r_val;
                right--;
                i--;
            } else {
                answer[i] = l_val;
                left++;
                i--;
            }
        }
        return answer;
    }
};