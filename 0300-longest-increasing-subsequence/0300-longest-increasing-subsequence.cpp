class Solution {
public:
// 10 9 2 5 3 7 101 18
// 1  1 1 1 1 1 1   1
// 
// if arr[j] < arr[i]
//      T[i] = max (T[i], T[j] + 1)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> T (nums.size (), 1);
        int mx = 0;
        for (int i = 1; i < nums.size (); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    T[i] = max (T[i], T[j] + 1);
                }
            }
        }
        for (int i = 0; i < T.size (); i++) {
            if (T[i] > mx)
                mx = T[i];
        }

        return mx;
    }
};