class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hashtable;
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        int i = 0;
        while (i < k){
            lo.push (nums[i++]);
        }

        for (int j = 0; j < k / 2; j++){
            hi.push (lo.top ());
            lo.pop ();
        }
        while (true){
            medians.push_back (k & 1 ? lo.top () : (double(lo.top ()) + double(hi.top ())) * 0.5);

            if (i >= nums.size ())
                break;

            int outNum = nums[i - k];
            int inNum = nums[i++];
            int balance = 0;
            balance += outNum <= lo.top () ? -1 : 1;
            hashtable[outNum]++;
            if (!lo.empty () && inNum <= lo.top ()){
                balance++;
                lo.push (inNum);
            }
            else{
                balance--;
                hi.push (inNum);
            }

            if (balance < 0){
                lo.push (hi.top ());
                hi.pop ();
                balance++;
            }

            if (balance > 0){
                hi.push (lo.top ());
                lo.pop ();
                balance--;
            }

            while (hashtable[lo.top ()]){
                hashtable[lo.top ()]--;
                lo.pop ();
            }

            while (!hi.empty () && hashtable[hi.top ()]){
                hashtable[hi.top ()]--;
                hi.pop ();
            }
        }
        return medians;
    }
};