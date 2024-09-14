class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size (); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push (s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if (st.empty ())
                    return false;
                char sym = st.top ();
                if (sym == '(' && s[i] == ')' || sym == '[' && s[i] == ']' || sym == '{' && s[i] == '}')
                    st.pop ();
                else
                    return false;
            }
        }
        return st.empty ();
    }
};