class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1_data; // nums1[i] -> freq
        for (int val : nums1) {
            n1_data[val]++;
        }
        vector<int> answer;
        for (int val : nums2) {
            unordered_map<int,int>::iterator it = n1_data.find (val);
            if (it == n1_data.end ())
                continue;
            it->second--;
            answer.push_back (it->first);
            if (it->second == 0)
                n1_data.erase (it);
        }
        return answer;
    }
};