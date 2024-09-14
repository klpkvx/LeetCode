class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = prices[0];
        int res = 0;
        for (int i = 0; i < prices.size (); i++){
            price = min (price, prices[i]);
            res = max (res, prices[i] - price);
        }
        return res;
    }
};