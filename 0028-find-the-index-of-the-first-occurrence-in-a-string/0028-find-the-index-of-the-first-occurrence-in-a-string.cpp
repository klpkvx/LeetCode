class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size (); i++){
            int ptr = 0;
            int pos = -1;
            int tmp_ptr = i;
            while (haystack[tmp_ptr] == needle[ptr]){
                if (pos == -1)
                    pos = tmp_ptr;
                tmp_ptr++;
                ptr++;
                if (ptr == needle.size ())
                    return pos;
            }
        }
        return -1;
    }
};