class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for(int left = 0; left < nums.size (); left++) {
            if (nums[left] != 0)
                nums[ptr++] = nums[left];
        }
        while (ptr != nums.size ()) {
            nums[ptr++] = 0;
        }
    }
};