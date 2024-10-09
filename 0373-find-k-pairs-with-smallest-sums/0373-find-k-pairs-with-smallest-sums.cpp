class Solution {
public:
    struct para {
        int index = 0;
        int sum = 0;
        para (int su, int ind) : sum (su), index (ind) {}
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        auto cmp = [] (para &lhs, para &rhs) {
            return !(lhs.sum < rhs.sum); // at the top pq is smallest sum pair
        };
        priority_queue<para, vector<para>, decltype(cmp)> pq (cmp);
        for (int i = 0; i < nums1.size (); i++) {
            pq.push (para (nums1[i] + nums2[0], 0));
        }

        while (k-- && !pq.empty ()) {
            const para &p = pq.top ();
            int sum = p.sum;
            int pos = p.index;
            result.push_back ({sum - nums2[pos], nums2[pos]});
            pq.pop ();
            if (pos + 1 < nums2.size ()) {
                // calculate sum of the next pair by subtracting the current second element from the sum
                // and adding the next element in nums2
                pq.push (para (sum - nums2[pos] + nums2[pos + 1], pos + 1));
            }
        }
        return result;
    }
}; 