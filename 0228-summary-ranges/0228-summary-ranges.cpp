class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty ())
            return {};
        vector<string> answer;
        for (int i = 0; i < nums.size (); i++) {
            int start = i;
            int end = i;

            while (i + 1 < nums.size () && abs ((long)nums[i] - (long)nums[i + 1]) == 1){
                end++;
                i++;
            }
            end = i;
            answer.push_back (end - start >= 1 ? to_string(nums[start]) + "->" + to_string (nums[end])
                                                : to_string (nums[start])
            );
        }
        return answer;
    }
};