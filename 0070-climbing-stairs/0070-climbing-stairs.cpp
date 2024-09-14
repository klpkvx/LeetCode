class Solution {
public:

    int solve (int n, vector<int> &data){
        if (n <= 0)
            return 0;

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        if (data[n] == -1)
            data[n] = solve (n - 1, data) + solve (n - 2, data); 

        return data[n];
    }

   int climbStairs (int n)
    {
        vector<int> data (n + 1, -1);

        return solve (n, data);
    }
};