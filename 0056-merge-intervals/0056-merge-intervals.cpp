class Solution {
public:
    // 1 .. 2 .. 3 .. 5
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin (), intervals.end ());

        vector<vector<int>> answer = {intervals[0]};
        for (int i = 1; i < intervals.size (); i++) {
            int start = answer.back ()[0];
            int end = answer.back ()[1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if (curr_start <= end) {
                answer.back ()[1] = max (curr_end, end);
            } else {
                answer.push_back ({curr_start, curr_end});
            }
        }
        return answer;
    }
};