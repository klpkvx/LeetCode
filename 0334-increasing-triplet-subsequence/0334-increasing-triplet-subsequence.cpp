class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size () < 2)
            return false;

        int l1 = INT_MAX;
        int l2 = INT_MAX;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] <= l1) {
                l1 = nums[i];
            } else if (nums[i] <= l2) {
                l2 = nums[i];
            } else
                return true;
        }
        return false;
    }
};