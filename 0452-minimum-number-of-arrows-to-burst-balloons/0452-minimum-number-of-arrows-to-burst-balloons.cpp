class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [] (vector<int> &a, vector<int> &b) {return a[1] < b[1];};
        sort(points.begin (), points.end (), cmp);
        int count = 0, right = 0;
        for (int i = 0; i < points.size (); i++) {
                if (count == 0 || points[i][0] > right) {
                    count++;
                    right = points[i][1];
                }
        }
        return count;
    }
};