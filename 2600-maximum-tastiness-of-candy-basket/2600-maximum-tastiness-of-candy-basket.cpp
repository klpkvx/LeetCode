class Solution {
public:

    bool check (vector<int> &prices, int price, int k){
        int count = 1;
        int prev = prices[0];
        for (int i = 1; i < prices.size (); i++){
            if (prices[i] - prev >= price){
                prev = prices[i];
                count++;
                if (count == k)
                    break;
            }
        }
        return count == k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort (price.begin (), price.end ());
        int left = 0;
        int right = 1e9;
        while (left <= right){
            int mid = (left + right) / 2;
            if (check (price, mid, k))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
};