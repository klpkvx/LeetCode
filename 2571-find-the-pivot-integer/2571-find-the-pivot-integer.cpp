class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            int left_sum = i * (i + 1) * 0.5;
            int right_sum = n * (n + 1) * 0.5 - i * (i - 1) * 0.5;
            if (left_sum == right_sum)
                return i;
        }
        return -1;
    }
};