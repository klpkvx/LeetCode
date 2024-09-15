class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int, int> n1_info; // nums1[i] -> count
        for (auto value : nums1){
            n1_info[value]++;
        }
        for (int i = 0; i < nums2.size (); i++){
            int candidate = nums2[i];
            auto it = n1_info.find (candidate);
            if (it == n1_info.end ())
                continue;
            if (it->second > 0){
                it->second--;
                answer.push_back (it->first);
            }
        }
        return answer;
    }
};