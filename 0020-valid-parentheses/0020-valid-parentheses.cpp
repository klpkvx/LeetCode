class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty ())
            {
                char sym = st.top ();
                if (c == '(' || c == '[' || c== '{')
                    st.push (c);
                else if (sym == '(' && c == ')' || sym == '{' && c == '}' || sym == '[' && c == ']')
                    st.pop ();
                else
                    return false;
            }
            else
                st.push (c);
        }
        return st.empty ();
    }
};