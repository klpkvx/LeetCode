class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int sz = mat.size ();
        for (int i = 0; i < mat.size (); i++) {
            sum += mat[i][i];
            sum += mat[i][sz - 1 - i];
        }
        if (sz % 2 == 1) {
            sum -= mat[sz /2][sz / 2];
        }
        return sum;
    }
};