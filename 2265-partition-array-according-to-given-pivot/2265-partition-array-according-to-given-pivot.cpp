class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low_ptr = 0;
        int high_ptr = 0;
        vector<int> low;
        vector<int> pivots;
        vector<int> high;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] < pivot) {
                low.push_back (nums[i]);
            } else if (nums[i] > pivot)
                high.push_back (nums[i]);
            else 
                pivots.push_back (nums[i]);

        }
        for (int i = 0; i < pivots.size (); i++) {
            low.push_back (pivots[i]);
        }
        for (int i = 0; i < high.size (); i++) {
            low.push_back (high[i]);
        }
        return low;
    }
};