class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [] (const pair<int,int> &left, const pair<int,int> &right){
            return left.second < right.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp)> pq (cmp);
        for (int i = 0; i < nums1.size (); i++) {
            pq.push ({nums1[i], nums2[i]});
        }
        auto cmp_elem = [] (const int &left, const int &right) {
            return left > right;
        };

        // Sort Elements in queue by increasing order
        priority_queue<int, vector<int>, decltype (cmp_elem)> k_range (cmp_elem);
        long long sum = 0;
        long long max_score = 0;
        while (!pq.empty ()) {
            long long n1 = pq.top ().first;
            long long n2 = pq.top ().second; // maximized min element in queue 
            k_range.push (n1);
            sum += n1;
            if (k_range.size () > k) {
                // remove the smallest in the range
                sum -= k_range.top ();
                k_range.pop ();
            }
            if (k_range.size () == k) {
                long long curr_score = sum * n2;
                max_score = max (max_score, curr_score);
            }
            pq.pop ();
        }
        return max_score;


        return max_score;
    }
};