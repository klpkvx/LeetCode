class Solution {
public:
// c[i] = count numbers: present at or before index i in A, B/ присутствует в индуксе i или перед ним

// [2,3,1]
// [3,1,2]
// 0 1 
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int sz = A.size ();
        int count = 0;
        unordered_set<int> a_set, b_set;
        vector<int> answer;
        for (int i = 0; i < sz; i++) {
            a_set.insert (A[i]);
            b_set.insert (B[i]);
            if (A[i] == B[i]) {
                count++;
                answer.push_back (count);
                continue;
            }

            if (b_set.find (A[i]) != b_set.end ()) count++;
            if (a_set.find (B[i]) != a_set.end ()) count++;

            answer.push_back (count);
        }
        return answer;
    }
};