class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> zipped_arr;
        for (int i = 0; i < nums1.size (); i++) {
            zipped_arr.push_back ({nums1[i], nums2[i]});
        }

        sort (zipped_arr.begin (), zipped_arr.end (), [] (const pair<int,int> &left, const pair<int,int> &right){
            return left.second > right.second;
        });

        auto cmp_elem = [] (const int &left, const int &right) {
            return left > right;
        };

        // Sort Elements in queue by increasing order
        priority_queue<int, vector<int>, decltype (cmp_elem)> k_range (cmp_elem);
        long long sum = 0;
        long long max_score = 0;
        for (const auto &[n1_, n2_] : zipped_arr) {
            long long n1 = n1_;
            long long n2 = n2_; // maximized element in queue
            k_range.push (n1);
            sum += n1;
            if (k_range.size () > k) {
                // remove the smalleft in the range
                sum -= k_range.top ();
                k_range.pop ();
            }
            if (k_range.size () == k) {
                long long curr_score = sum * n2;
                max_score = max (max_score, curr_score);
            }
        }
        return max_score;


        return max_score;
    }
};