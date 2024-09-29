class Solution {
public:
// 2 2 1 1 1 2 2
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (count == 0) {
                elem = nums[i];
                count++;
            } else {
                if (nums[i] == elem)
                    count++;
                else
                    count--;
            }
        }
        return elem;
    }
};