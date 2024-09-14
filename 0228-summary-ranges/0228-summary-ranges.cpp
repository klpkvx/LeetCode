class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty ())
            return {};
        int start = nums[0];
        vector<string> answer;
        for (int i = 1; i < nums.size (); i++){
            if (nums[i] != nums[i - 1] + 1){
                
                if (start == nums[i - 1])
                    answer.push_back (to_string (start));
                else{
                    answer.push_back (to_string (start) + "->" + to_string (nums[i - 1]));
                }
                start = nums[i];
            }
        }
        if (start == nums.back ()){
            answer.push_back (to_string (start));
        } else{
            answer.push_back (to_string (start) + "->" + to_string (nums.back ()));
        }
        return answer;
    }
};