class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_data{nums1.begin (), nums1.end ()};
        unordered_set<int> n2_data{nums2.begin (), nums2.end ()};
        vector<int> n1_values;
        vector<int> n2_values;
        for (int num : n1_data) {
            if (!n2_data.contains (num))
                n1_values.push_back (num);
        }
        for (int num : n2_data) {
            if (!n1_data.contains (num))
                n2_values.push_back (num);
        }
        return {n1_values, n2_values};
    }
};