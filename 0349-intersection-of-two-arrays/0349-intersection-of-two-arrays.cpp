class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> n1_unique;
        unordered_set<int> n2_unique;
        for (int i = 0; i < nums1.size (); i++){
            n1_unique.insert (nums1[i]);
        }

        for (int i = 0; i < nums2.size (); i++){
            n2_unique.insert (nums2[i]);
        }
        const auto &container = n1_unique.size () < n2_unique.size () ? n1_unique : n2_unique;
        const auto &cmp_container = n1_unique.size () < n2_unique.size () ? n2_unique : n1_unique;
        for (auto num : container){
            if (cmp_container.contains (num))
                result.push_back (num);
        }
        return result;
    }
};