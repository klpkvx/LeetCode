class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < nums.size (); i++){
            while (!q.empty () && q.top ().second <= i - k){
                q.pop ();
            }
            q.push ({nums[i], i});
            if (i >= k - 1)
                answer.push_back (q.top().first);

        }
        return answer;
    }
};