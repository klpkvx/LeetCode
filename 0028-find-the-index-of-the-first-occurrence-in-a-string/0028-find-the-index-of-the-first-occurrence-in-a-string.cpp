class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size ();) {
            int start = i;
            int ptr = 0;
            while (i < haystack.size () && ptr < needle.size () && haystack[i] == needle[ptr]) {
                i++;
                ptr++;
            }
            if (ptr == needle.size ())
                return start;
            i = start + 1;
        }
        return -1;
    }
};