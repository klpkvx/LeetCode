class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int equal = 0;
        int low = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] < pivot)
                low++;
            else if (nums[i] == pivot)
                equal++;
        }
        int high = equal + low;
        int same = low;
        low = 0;
        vector<int> answer (nums.size ());
        for (int elem : nums) {
            if (elem < pivot) {
                answer[low++] = elem;
            } else if (elem == pivot) {
                answer[same++] = elem;
            } else {
                answer[high++] = elem;
            }
        }
        return answer;
    }
};