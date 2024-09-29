class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int err = 0;
        for (char c : s) {
            if (c == '[')
                st.push (c);
            else if (c == ']') {
                if (!st.empty () && st.top () == '[')
                    st.pop ();
            }
        }
        return (st.size () + 1) / 2;  
    }
};