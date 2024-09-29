class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin (), nums.end ());
        set<vector<int>> data;

        for (int i = 0; i + 1 < nums.size (); i++) {
            int left = i + 1;
            int right = nums.size () - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    data.insert ({nums[i],nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }
        return vector<vector<int>> (data.begin (), data.end ());
    }
};