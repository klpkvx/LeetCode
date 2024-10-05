class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> data;
        for (int i = 0; i < matrix.size (); i++) {
            for (int j = 0; j < matrix[i].size (); j++) {
                if (matrix[i][j] == 0) {
                    data.insert ({i, j});
                }
            }
        }

        for (const auto &elem : data) {
            int i = elem.first;
            int j = elem.second;
            for (int k = 0; k < matrix[i].size (); k++) 
                matrix[i][k] = 0;
            for (int k = 0; k < matrix.size (); k++) {
                matrix[k][j] = 0;
            }
        }
    }
};