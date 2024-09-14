class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets {
             {'(', ')'}, {'{', '}'}, {'[', ']'}
        };
        for (int i = 0; i < s.size (); i++){
            if (brackets.contains (s[i]))
                st.push (s[i]);
            else{
                if (st.empty ()  ||  brackets[st.top ()] != s[i])
                    return false;
                else
                    st.pop ();
            }
        }
        return st.empty ();
    }
};