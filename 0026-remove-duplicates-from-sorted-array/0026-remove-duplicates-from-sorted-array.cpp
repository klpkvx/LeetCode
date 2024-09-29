class Solution {
public:
// 1 2 3 4 
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[ptr] == nums[i]) {
                continue;
            } else {
                nums[++ptr] = nums[i];
            }
        }
        return ptr + 1;
    }
};