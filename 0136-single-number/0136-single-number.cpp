class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate (nums.begin (), nums.end (), int{}, [] (int l, int v) { return l ^ v; });
    }
};