class Solution {
public:
// Найти подмассив у которого сумма чисел равна x. Вернуть минимальную длину. Если такого массива нет, вернуть -1.
    int minOperations(vector<int>& nums, int x) {
        int sz = nums.size ();
        int totalsum = accumulate (nums.begin (), nums.end (), 0);
        int target = totalsum - x;
        unordered_map<int, int> mp = {{0, -1}}; // pref_sum -> index;
        int presum = 0, maxsub = INT_MIN;
        if (x == totalsum) return sz;

        for (int i = 0; i < sz; i++) {
            presum += nums[i];
            if (mp.contains (presum - target)){
                int sub = i - mp[presum - target];
                maxsub = max (maxsub, sub);
            }
            mp[presum] = i;
        }
        if (maxsub == INT_MIN) return -1;

        return sz - maxsub;
    }
};