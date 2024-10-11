class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_data;
        for (int val : nums1) {
            n1_data.insert (val);
        }
        vector<int> answer;
        for (int val : nums2) {
            if (n1_data.contains (val)) {
                answer.push_back (val);
                n1_data.erase (val);
            }
        }
        return answer;
    }
};