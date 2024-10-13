class Solution {
public:
    string simplifyPath(string path) {
        string answer;
        stack<string> st;
        for (int i = 0; i < path.size (); i++) {
            string tmp;
            if (path[i] == '/')
                continue;
            
            while (i < path.size () && path[i] != '/')
                tmp += path[i++];

            if (tmp == ".")
                continue;
            else if (tmp == "..") {
                if (!st.empty ())
                    st.pop ();
            } else {
                st.push (tmp);
            }
        }
        while (!st.empty ()) {
            answer = "/" + st.top () + answer;
            st.pop ();
        }
        if (answer.empty ())
            return "/";
        return answer;
    }
};