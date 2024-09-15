class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> n1_unique;
        for (int i = 0; i < nums1.size (); i++){
            n1_unique.insert (nums1[i]);
        }

        for (int i = 0; i < nums2.size (); i++){
            if (n1_unique.contains (nums2[i])){
                n1_unique.erase (nums2[i]);
                result.push_back (nums2[i]);
            }
        }
        return result;
    }
};