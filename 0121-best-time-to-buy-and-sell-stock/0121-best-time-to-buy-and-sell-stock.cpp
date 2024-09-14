class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = prices[0];
        int total = 0;
        for (int i = 1; i < prices.size (); i++){
            price = min (price, prices[i]);
            total = max (total, prices[i] - price);
        }
        return total;
    }
};