class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [] (const pair<int,int> &left, const pair<int,int> &right) {
            return left.first > right.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto i : arr) {
            pq.push ({abs (x - i), i});
        }

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back (pq.top ().second);
            pq.pop ();
        }

        sort (answer.begin (), answer.end ());
        return answer;
    }
};