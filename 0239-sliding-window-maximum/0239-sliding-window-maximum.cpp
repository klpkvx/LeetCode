class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> w;
        for (int i = 0; i < nums.size (); i++){
            while (!w.empty () && w.front () <= i - k)
                w.pop_front ();
            while (!w.empty () && nums[w.back ()] <= nums[i])
                w.pop_back ();
            w.push_back (i);
            if (i >= k - 1)
                answer.push_back (nums[w.front ()]);
        }
        return answer;
    }
};