class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice=prices[0];
        int currentPrice =0;
        int profit =0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i]<buyPrice){
                buyPrice =prices[i];
            }
            else{
                currentPrice = prices[i]-buyPrice;
                profit = max(currentPrice, profit);
            }
        }
        return profit;
    }
};
