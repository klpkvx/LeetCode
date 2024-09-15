class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size (); i++){
            if (nums[i] == 1){
                tmp++;
                mx = max(mx, tmp);
            } else{
                tmp = 0;
            }
        }
        return mx;
    }
};