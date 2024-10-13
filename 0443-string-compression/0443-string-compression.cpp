class Solution {
public:
    int compress(vector<char>& chars) {
        int ptr = 0;
        for (int i = 0; i < chars.size (); i++) {
            chars[ptr++] = chars[i];
            int count = 1;
            while (i + 1 < chars.size () && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            if (count > 1) {
                string s = to_string (count);
                for (int i = 0; i < s.size (); i++)
                    chars[ptr++] = s[i];
            }
        }
        return ptr;
    }
};