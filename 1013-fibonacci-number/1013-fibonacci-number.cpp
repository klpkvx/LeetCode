class Solution {
public:
    int fiib (int n, unordered_map<int, int> &data)
    {
        if (n == 0 || n == 1)
            return n;

        if (data.contains (n))
            return data[n];
        else
            data[n] = fiib (n - 1, data) + fiib (n - 2, data);

        return data[n];
    }
    int fib(int n) {
        unordered_map<int,int> data = { {0, 0}, {1, 1} };
        fiib (n, data);
        return data[n];
    }
};