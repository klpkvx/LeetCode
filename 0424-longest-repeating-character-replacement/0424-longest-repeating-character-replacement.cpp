class Solution {
public:

    int max_count (unordered_map<char,int>&data){
        int max = -1;
        for (auto &[elem, count] : data)
            if (count > max)
                max = count;
        return max;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> data; // char -> freq;
        int result = 0;
        int left = 0;
        int right = 0;
        for (int right = 0; right < s.size (); right++){

            data[s[right]]++;
            while (right - left + 1 - max_count (data) > k){
                data[s[left]]--;
                left++;
            }

            result = max (result, right - left + 1);
        }
        return result;
    }
};