class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size (); i++) {
            price = min (price, prices[i]);
            max_profit = max (max_profit, prices[i] - price);
        }
        return max_profit;
    }
};