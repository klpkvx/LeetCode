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
        int i = 0, j = low, k = equal + low;
        vector<int> answer (nums.size ());
        for (int elem : nums) {
            if (elem < pivot) {
                answer[i++] = elem;
            } else if (elem == pivot) {
                answer[j++] = elem;
            } else {
                answer[k++] = elem;
            }
        }
        return answer;
    }
};