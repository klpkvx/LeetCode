class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int close = 0;
        for (char c : s) {
            if (c == '(')
                st.push (c);
            else {
                if (!st.empty () && st.top () == '(')
                    st.pop ();
                else
                    close++;
            }
        }
        return st.size () + close;
    }
};