class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res (nums1.size () + nums2.size ());
        int r_ptr = 0, l = 0, r = 0, val = 0;
        for (r_ptr = 0; r_ptr < res.size (); r_ptr++) {
            if (l < nums1.size () && r < nums2.size ())
                val = nums1[l] < nums2[r] ? nums1[l++] : nums2[r++];
            else if (l < nums1.size ())
                val = nums1[l++];
            else if (r < nums2.size ())
                val = nums2[r++];
            res[r_ptr] = val;
        }

        if (res.empty ())
            return 0;
        if (res.size () == 1)
            return res[0];

        int ind = (nums1.size () + nums2.size ()) / 2 ;
        if (res.size () % 2 == 0)
            return (res[ind] + res[ind - 1]) / 2.;
        else
            return res[ind];
    }
};