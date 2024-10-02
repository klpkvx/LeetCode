class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p_data; // sym -> freq
        unordered_map<string, int> s_data; // word -> freq
        istringstream in(s); 
        string word;
        int i = 0;
        for (; in >> word; i++) {
            if (i == pattern.size () || p_data[pattern[i]] != s_data[word])
                return false;
            p_data[pattern[i]] = i + 228;
            s_data[word] = i + 228;
        }
        return i == pattern.size ();
    }
};