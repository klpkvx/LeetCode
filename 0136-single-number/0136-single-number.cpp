class Solution {
public:
    int singleNumber(vector<int>& nums) {        ios::sync_with_stdio(false);

        return accumulate (nums.begin (), nums.end (), int{}, [] (int l, int v) { return l ^ v; });
    }
};