class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for (int right = 0; right < chars.size ();) {
            char curr = chars[right];
            int count = 0;
            while (right < chars.size () && curr == chars[right]) {
                count++;
                right++;
            }
            chars[ans++] = curr;
            if (count > 1) {
                for (char c : to_string (count)) {
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    }
};