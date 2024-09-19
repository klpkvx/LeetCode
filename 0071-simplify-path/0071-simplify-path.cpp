class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str;
        for (int i = 0; i < path.size (); i++) {
            if (path[i] == '/')
                continue;
            
            string tmp;
            while (i < path.size () && path[i] != '/'){
                tmp.push_back (path[i++]);
            }

            if (tmp == ".."){
                if (!st.empty ())
                    st.pop ();
            } else if (tmp == ".") {
                continue;
            } else {
                st.push (tmp);
            }
        }

        while (!st.empty ()) {
            str = "/" + st.top () + str;
            st.pop ();
        }
        if (str.empty ()) {
            return "/";
        }
        return str;
    }
};