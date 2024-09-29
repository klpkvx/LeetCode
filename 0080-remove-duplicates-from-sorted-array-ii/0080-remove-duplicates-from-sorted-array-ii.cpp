class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 1;
        int count = 1;
        for (int i = 1; i < nums.size (); i++) {
            if (nums[i - 1] != nums[i]) {
                count = 1;
                nums[ptr++] = nums[i];
            } else {
                count++;
                if (count == 2)
                    nums[ptr++] = nums[i];
            }
        }
        return ptr;
        
    }
};