class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_data {nums1.begin (), nums1.end ()};

        vector<int> answer;
        for (int val : nums2) {
            if (n1_data.contains (val))
                continue;
            answer.push_back (val);
            n1_data.erase (val);
        }
        return answer;
    }
};