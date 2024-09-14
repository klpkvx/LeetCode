class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = nums[0];
        for (int i = 0; i < nums.size (); i++){
            if (count == 0){
                elem = nums[i];
                count = 1;
            } else if (elem == nums[i]){
                count++;
            } else
                count--;
        }

        return elem;
    }
};