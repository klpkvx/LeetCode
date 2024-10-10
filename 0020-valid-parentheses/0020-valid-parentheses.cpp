class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size (); i++) {
            char letter = s[i];
            if (letter == '(' || letter == '[' || letter == '{') {
                st.push (letter);
            } else if (!st.empty () && (st.top () == '(' && letter == ')' || st.top () == '[' && letter == ']' || st.top () == '{' && letter == '}'))
                    st.pop ();
            else
                return false;
        }
        return st.empty ();
    }
};