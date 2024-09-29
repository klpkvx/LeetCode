class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        int i = 0;
        for ( i = 0; i < nums.size () && i <= max_jump; i++) {
            max_jump = max (max_jump, i + nums[i]);
        }
        return i == nums.size ();
    }
};