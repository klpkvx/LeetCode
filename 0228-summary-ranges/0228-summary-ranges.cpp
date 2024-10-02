class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        for (int i = 0; i < nums.size (); i++) {
            int start = i;
            int end = i;
            
            while (i + 1 < nums.size () && (long long)nums[i + 1] - (long long)nums[end] == 1) {
                i++;
                end = i;
            }

            answer.push_back (
                             end - start == 0 ?
                             to_string(nums[start]) : 
                             to_string (nums[start]) + "->" + to_string (nums[end])
                             );
        }
        return answer;
    }
};