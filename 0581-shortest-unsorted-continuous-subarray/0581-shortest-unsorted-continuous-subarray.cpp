class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted (nums);
        sort (sorted.begin (), sorted.end ());
        int left = 0;
        int right = nums.size () - 1;
        while (left < nums.size () && sorted[left] == nums[left]){
            left++;
        }
        while (right > left && sorted[right] == nums[right]) {
            right--;
        }
        return right - left + 1;
    }
};