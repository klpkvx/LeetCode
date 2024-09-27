class Solution {
public:
// c[i] = count numbers: present at or before index i in A, B/ присутствует в индуксе i или перед ним

// [2,3,1]
// [3,1,2]
// 0 1 
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int sz = A.size ();
        int count = 0;
        unordered_map<int, int> mp; // elem -> count
        vector<int> answer;
        for (int i = 0; i < sz; i++) {
            mp[A[i]]++;
            if (mp[A[i]] == 2) count++;
            mp[B[i]]++;
            if (mp[B[i]] == 2) count++;
            answer.push_back (count);
        }
        return answer;
    }
};