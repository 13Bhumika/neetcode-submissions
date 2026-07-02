class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> msp(prices.size());
        int maxProfit=0;
        int price=-1e9;

        for(int i=prices.size()-1; i>=0; i--){
            msp[i]= max(price, prices[i]);
            price= max(price, prices[i]);
        }
        for(int i=0; i<prices.size()-1; i++){
            int buy= prices[i];
            int sell= msp[i+1];
            maxProfit= max(maxProfit, sell-buy);
        }
        return maxProfit;
    }
};
