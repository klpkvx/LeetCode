class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        auto cmp = [] (const pair<int,int> &left, const pair<int,int> &right) {
            return left.first > right.first;
        };

        auto cmp2 = [] (const pair<int,int> &left, const pair<int,int> &right) {
            return left.second < right.second;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp)> minheap (cmp); // capital -> profit
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp2)> maxheap (cmp2);
        for (int i = 0; i < profits.size (); i++) {
            minheap.push ({capital[i], profits[i]});
        }
        
        while (k--) {
            while (!minheap.empty () && minheap.top ().first <= w) {
                maxheap.push ({minheap.top ().first, minheap.top ().second});
                minheap.pop ();
            }
            if (maxheap.empty ())
                break;
            w += maxheap.top ().second;
            maxheap.pop ();
        }
        return w;
    }
};