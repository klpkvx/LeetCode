class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [] (const pair<int,int> &left, const pair<int,int> &right) {
            return left.first > right.first;
        };
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < arr.size (); i++) {
            pq.push ({abs (x - arr[i]), arr[i]});
            while (pq.size () > k)
                pq.pop ();
        }
        vector<int> answer;
        while (k-- > 0){
            answer.push_back (pq.top ().second);
            pq.pop ();
        }

        sort (answer.begin (), answer.end ());
        return answer;
    }
};