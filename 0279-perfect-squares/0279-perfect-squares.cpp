class Solution {
public:
    int numSquares(int n) {
        vector<int> cnt_perf_squares (n + 1,INT_MAX);
        cnt_perf_squares[0] = 0;
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                cnt_perf_squares[i] = min (cnt_perf_squares[i], cnt_perf_squares[i - j * j] + 1);
            }
        }
        return cnt_perf_squares.back ();
    }
};