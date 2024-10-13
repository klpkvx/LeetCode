class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size ();
        int m = grid[0].size ();
        vector<vector<int>> xx (n, vector<int> (m));
        vector<vector<int>> yy (n, vector<int> (m));
        long long p = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                xx[i][j] = p;
                p *= grid[i][j];
                p %= 12345;
            }
        }
        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                yy[i][j] = p;
                p *= grid[i][j];
                p %= 12345;
            }
        }
        vector<vector<int>> answer (n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer[i][j] = xx[i][j] * yy[i][j];
                answer[i][j] %= 12345;
            }
        }
        return answer;
    }
};