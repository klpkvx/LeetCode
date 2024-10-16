class Solution {
public:
// [a, b] , [c, d] -> b < c
    int findLongestChain(vector<vector<int>>& pairs) {
        sort (pairs.begin (), pairs.end (), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });

        int answer = 0;
        int curr = INT_MIN;
        for (int i = 0; i < pairs.size (); i++){
            if (curr < pairs[i][0]) {
                curr = pairs[i][1];
                answer++;
            }
        }
        return answer;
    }
};