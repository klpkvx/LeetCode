class Solution {
public:
    int busyStudent(vector<int>& start, vector<int>& end, int target) {
        int sz = end.size ();
        int count = 0;
        for (int i = 0; i < sz; i++) {
            if (start[i] <= target && target <= end[i])
                count++;
        }
        return count;
    }
};