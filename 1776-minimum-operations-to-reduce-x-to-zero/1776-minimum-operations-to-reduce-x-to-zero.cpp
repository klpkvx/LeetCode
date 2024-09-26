class Solution {
public:
// Найти подмассив у которого сумма чисел равна x. Вернуть минимальную длину. Если такого массива нет, вернуть -1.
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate (nums.begin (), nums.end (), 0) - x;
        int sum = 0;
        int left = 0;
        int right = 0; 
        int ans = -1;
        int sz = nums.size ();
        for (int right = 0; right < sz; right++) {
            sum += nums[right];
            while (left < sz && sum > target) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) {
                ans = max (ans, right - left + 1);
            }
        }
        return ans == -1 ? -1 : sz - ans;
    }
};