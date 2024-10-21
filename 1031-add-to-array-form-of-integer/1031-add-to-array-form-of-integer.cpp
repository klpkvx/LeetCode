class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> answer;
        int i = num.size () - 1;
        int carry = 0;
        int digit = 0;
        while (i >= 0 || k || carry) {
            digit = (i >= 0 ? (num[i--]) : 0) + k % 10 + carry;
            answer.push_back (digit % 10);
            carry = digit / 10;
            k /= 10;
        }
        reverse (answer.begin (), answer.end ());
        return answer;
    }
};