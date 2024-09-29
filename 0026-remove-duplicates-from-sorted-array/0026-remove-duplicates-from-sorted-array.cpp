class Solution {
public:
// 1 2 3 4 
    int removeDuplicates(vector<int>& nums) {
        int ptr = 1;
        for (int i = 1; i < nums.size (); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};