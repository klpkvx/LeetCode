class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for (int i = num.size () - 1; i >= 0 && k > 0; i--) {
            int digit = k % 10;
            k /= 10;
            int value = num[i] + digit + carry;
            carry = value / 10;
            num [i] = value % 10;
        }

        while (k > 0 || carry) {
            int value = k % 10 + carry;
            carry = value / 10;
            num.insert (num.begin (), value % 10);
            k /= 10;
        }

        return num;
    }
};