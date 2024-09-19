class Solution {
public:
    // 1 .. 2 .. 3 .. 5
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin (), intervals.end ());

        vector<vector<int>> answer = {intervals[0]};
        for (int i = 1; i < intervals.size (); i++) {
            if (intervals[i][0] <= answer.back ()[1]) {
                answer.back ()[1] = max (intervals[i][1], answer.back ()[1]);
            } else {
                answer.push_back ({intervals[i][0], intervals[i][1]});
            }
        }
        return answer;
    }
};