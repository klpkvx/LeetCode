class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size (); i++)
        {
            int left = 0;
            int right = matrix[i].size () - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int value = matrix[i][mid];
                if (value == target)
                    return true;
                else if (value < target)
                    left = mid + 1;
                else    
                    right = mid - 1;
            }
        }
        return false;
    }
};