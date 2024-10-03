class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<string> st;
        for (int i = 0; i < path.size (); i++) {
            if (path[i] == '/')
                continue;
            string tmp;
            while (i < path.size () && path[i] != '/')
                tmp += path[i++];
            if (tmp == ".")
                continue;
            else if (tmp == "..") {
                if (!st.empty ())
                    st.pop ();
            }
            else
                st.push (tmp);
        }
        while (!st.empty ()) {
            ans = "/" + st.top () + ans;
            st.pop ();
        }
        if (ans.empty ()) return "/";
        return ans;
    }
};