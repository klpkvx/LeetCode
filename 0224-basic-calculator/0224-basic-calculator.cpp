class Solution {
public:
    int calculate(string s) {
        int answer = 0;
        int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st; // calc value, sign before next bracket ()
        for (int i = 0; i < s.size (); i++) {
            if (isdigit (s[i])) {
                long long num = 0;
                while (i < s.size () && isdigit (s[i]))
                    num = num * 10 + s[i++] - '0';
                i--;
                sum += num * sign;
                sign = 1;
            } else if (s[i] == '(') {
                st.push ({sum, sign});
                sum = 0;
                sign = 1;
            } else if (s[i] == ')') {
                sum = st.top ().first  + st.top ().second * sum;
                st.pop ();
            } else if (s[i] == '-')
                sign = -1 * sign;
        }
        return sum;
    }
};