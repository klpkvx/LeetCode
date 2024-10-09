class Solution {
public:
    int answer = 0;
    int tmp = 0;
    void dfs (vector<vector<int>> &grid, int i, int j) {
            if (i < 0 || j < 0 || i >= grid.size () || j >= grid[0].size ())
                return; 
            if (grid[i][j] == 0)
                return;

            tmp++;
            grid[i][j] = 0;

            dfs (grid, i, j + 1);
            dfs (grid, i, j - 1);
            dfs (grid, i + 1, j);
            dfs (grid, i - 1, j);
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size (); i++) {
            for (int j = 0 ; j < grid[0].size (); j++) {
                if (grid[i][j] == 1) {
                    tmp = 0;
                    dfs (grid, i, j);
                    answer = max (answer, tmp);
                }
            }
        }
        return answer;
    }
};