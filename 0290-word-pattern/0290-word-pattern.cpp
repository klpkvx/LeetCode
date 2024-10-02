class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        for (int i = 0; i < s.size (); i++) {
            string curr_word;
            while (i < s.size () && s[i] != ' ')
                curr_word.push_back (s[i++]);
            if (!curr_word.empty ())
                words.push_back (std::move (curr_word)); 
        }

        if (pattern.size () != words.size ())
            return false;
        int sz = pattern.size ();
        unordered_map<char, string> p_map;
        unordered_map<string, char> w_map;
        for (int i = 0; i < sz; i++) {
            const string& word = words[i];
            char letter = pattern[i];
            if (p_map.contains (letter) && p_map[letter] != word)
                return false;
            if (w_map.contains (word) && w_map[word] != letter)
                return false;
            p_map[letter] = word;
            w_map[word] = letter;
        }
        return true;
    } 
};