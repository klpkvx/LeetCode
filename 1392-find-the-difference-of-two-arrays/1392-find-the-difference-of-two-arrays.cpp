class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_data;
        unordered_set<int> n2_data;
        for (int i = 0; i < nums1.size (); i++) {
            n1_data.insert (nums1[i]);
        }

        for (int j = 0; j < nums2.size (); j++) {
            n2_data.insert (nums2[j]);
        }
        vector<int> n1_answer;
        vector<int> n2_answer;
        for (int i = 0; i < nums2.size (); i++) {
            if (!n1_data.contains (nums2[i])) {
                n1_answer.push_back (nums2[i]);
                n1_data.insert (nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size (); i++) {
            if (!n2_data.contains (nums1[i])) {
                n2_answer.push_back (nums1[i]);
                n2_data.insert (nums1[i]);
            }
        }
        return {n2_answer, n1_answer};

    }
};