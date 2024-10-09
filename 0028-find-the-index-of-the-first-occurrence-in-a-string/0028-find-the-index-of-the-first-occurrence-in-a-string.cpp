class Solution {
public:
    int strStr(string haystack, string needle) {
        int needed_size = needle.size ();
        for (int i = 0; i < haystack.size ();) {
            int start = i;
            int ptr = 0;
            while (ptr < needed_size && i < haystack.size () && needle[ptr] == haystack[i]) {
                ptr++;
                i++;
            }
            if (ptr == needed_size)
                return start;
            i = start + 1;
        }
        return -1;
    }
};