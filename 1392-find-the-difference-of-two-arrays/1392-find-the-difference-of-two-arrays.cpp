class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_values;
        unordered_set<int> nums2_values;
        vector<int> nums1_which_not_in_nums2;
        vector<int> nums2_which_not_in_nums1;

        for (int value : nums1)
            nums1_values.insert (value);
        for (int value : nums2)
            nums2_values.insert (value);
        for (int elem : nums1_values){
            if (!nums2_values.contains (elem))
                nums1_which_not_in_nums2.push_back (elem);
        }

        for (int elem : nums2_values){
            if (!nums1_values.contains (elem))
                nums2_which_not_in_nums1.push_back (elem);
        }

        return {nums1_which_not_in_nums2, nums2_which_not_in_nums1};
    }
};