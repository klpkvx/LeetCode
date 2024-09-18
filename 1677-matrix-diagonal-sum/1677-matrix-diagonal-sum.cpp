class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int main_diag = 0;
        int second_diag = 0;
        int sz = mat.size ();
        for (int i = 0; i < mat.size (); i++) {
            main_diag += mat[i][i];
            if (i != sz - 1 - i)
            second_diag += mat[i][sz - 1 - i];
        }
        return main_diag + second_diag;
    }
};