class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int main_diag = 0;
        int second_diag = 0;
        for (int i = 0; i < mat.size (); i++) {
            main_diag += mat[i][i];
            second_diag += mat.size () - 1 - i >= 0 ? mat[i][mat.size () - 1 - i] : 0;
            if (i == mat.size () - 1 - i)
                second_diag -= mat[i][i];
        }
        return main_diag + second_diag;
    }
};