class Solution {
public:
    int compress(vector<char>& chars) {
        int ptr = 0;
        for (int i = 0; i < chars.size ();) {
            char letter = chars[i];
            int count = 0;
            while (i < chars.size () && chars[i] == letter) {
                count++;
                i++;
            }
            chars[ptr++] = letter;
            if (count > 1) {
                for (char digit : to_string (count))
                    chars[ptr++] = digit;
            }
        }
        return ptr;
    }
};