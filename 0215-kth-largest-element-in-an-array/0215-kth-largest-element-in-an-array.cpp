class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        auto cmp = [] (const int &lhs,const int &rhs) {
            return lhs < rhs;
        };
        
        priority_queue<int, vector<int>, decltype (cmp)> data (cmp);
        for (int i : nums)
            data.push (i);
        while (k--) {
            if (k == 0) 
                return data.top ();
            data.pop ();
        }
        return -1;
    }
};