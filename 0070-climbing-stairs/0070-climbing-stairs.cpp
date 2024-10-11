class Solution {
public:

    unordered_map<int, int> data = {
        {1, 1},
        {2, 2}
    }; // n -> sum
    
    int solve (int n) {
        if (n <= 0)
            return 0;
        if (data.contains (n))
            return data[n];
        data[n - 1] = solve (n - 1);
        data[n - 2] = solve (n - 2);
        return data[n - 1] + data[n - 2];
    }

    int climbStairs(int n) {
        return solve (n);
    }
};