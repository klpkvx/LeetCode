class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;

        while (i < intervals.size () && intervals[i][1] < newInterval[0])
            answer.push_back (intervals[i++]);

        while (i < intervals.size () && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min (intervals[i][0], newInterval[0]);
            newInterval[1] = max (intervals[i][1], newInterval[1]);
            i++;
        }
        
        answer.push_back (newInterval);

        while (i < intervals.size ()) {
            answer.push_back (intervals[i++]);
        }

        return answer;
    }
};