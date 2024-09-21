class Solution {
public:
// 10 9 2 5 3 7 101 18
// 1  1 1 1 1 1 1   1
// 
// if arr[j] < arr[i]
//      T[i] = max (T[i], T[j] + 1)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> answer = {nums[0]};
        for (int i = 1; i < nums.size (); i++) {
            if (nums[i] > answer.back ()) {
                answer.push_back (nums[i]);
            } else {
                int left = 0, right = answer.size () - 1;
                int ans = -1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (answer[mid] < nums[i]) {
                        ans = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                answer[ans + 1] = nums[i];
            }
        }
        return answer.size ();
    }
};