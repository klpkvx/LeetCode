class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin (), intervals.end ());
        vector<vector<int>> result;
        for (auto &interval : intervals){
            if (result.empty ())
                result.push_back (interval);
            else if (result.back ()[1] >= interval[0])
                result[result.size () - 1][1] = max (result[result.size () - 1][1], interval[1]);
            else
                result.push_back (interval);
        }
        return result;
    }
};