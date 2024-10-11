class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int price = prices[0];
        for (int i = 1; i < prices.size (); i++) {
            price = min (price, prices[i]);
            total_profit = max (total_profit, prices[i] - price);
        }
        return total_profit;
    }
};