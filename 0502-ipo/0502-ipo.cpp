class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmp = [] (const pair<int,int> &lhs, const pair<int,int> &rhs) {
            return lhs.first > rhs.first; // min capital at the top capq
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp)> capq (cmp); // capital -> profit
        for (int i = 0; i < capital.size (); i++) {
            capq.push ({capital[i], profits[i]});
        }
        auto cmp_pro = [] (const pair<int,int> &lhs, const pair<int,int> &rhs) {
            return lhs.second < rhs.second; // max profit at the top proq
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp_pro)> proq (cmp_pro); // capital -> profit
        while (k--) {
            while (!capq.empty () && capq.top ().first <= w) {
                proq.push ({capq.top ().first, capq.top ().second});
                capq.pop ();
            }
            if (proq.empty ())
                break;
            w += proq.top ().second;
            proq.pop ();
        }
        return w;
    }
};