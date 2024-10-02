class Solution {
public:
    int next_number (int n) {
        int new_number = 0;
        while (n != 0) {
            int dig = n % 10;
            new_number += dig * dig;
            n /= 10;
        }
        return new_number;
    }

    bool isHappy(int n) {
        unordered_set<int> data;
        while (n != 1 && !data.contains(n)) {
            data.insert(n);
            n = next_number(n);
        }
        return n == 1;
    }
};