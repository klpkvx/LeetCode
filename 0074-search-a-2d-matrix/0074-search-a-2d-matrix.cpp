class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size ();
        int cols = matrix[0].size ();
        int left = 0;
        int right = rows * cols - 1; // a[i]][j] = a[i * cols + j];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] > target) {
                right = mid - 1;
            } else
                left = mid + 1;
            
        }
        return false;
    }
};