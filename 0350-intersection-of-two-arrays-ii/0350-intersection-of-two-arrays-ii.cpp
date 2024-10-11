class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1_data; // nums1[i] -> freq
        for (int val : nums1) {
            n1_data[val]++;
        }
        vector<int> answer;
        for (int val : nums2) {
            if (!n1_data.contains (val))
                continue;
            n1_data[val]--;
            answer.push_back (val);
            if (n1_data[val] == 0)
                n1_data.erase (val);
        }
        return answer;
    }
};