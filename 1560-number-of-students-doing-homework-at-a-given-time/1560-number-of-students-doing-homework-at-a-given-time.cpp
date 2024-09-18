class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int answer = 0;
        int sz = endTime.size ();
        for (int i = 0 ; i < sz; i++) {
            int start = startTime[i];
            int end = endTime[i];
            if (start <= queryTime && queryTime <= end) {
                answer++;
            }
        }
        return answer;
    }
};