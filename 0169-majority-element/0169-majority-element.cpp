class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frq; // num -> freq
        for (int i = 0; i < nums.size (); i++)
            frq[nums[i]]++;

        int mx_freq = -1;
        int top_val = 0;
        for (auto &[value, count] : frq){
            if (count > mx_freq){
                mx_freq = count;
                top_val = value;
            }
        }
        return top_val;
    }
};