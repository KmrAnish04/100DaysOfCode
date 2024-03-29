class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int amountToBuy = prices[0];
        int maxProfit = 0;
            
        for(int i=0;i<prices.size(); i++){
            if(prices[i]<amountToBuy){
                amountToBuy = prices[i];
            }
            else if(prices[i]-amountToBuy > maxProfit){
                maxProfit = prices[i]-amountToBuy;
            }
        }
        return maxProfit;
    }
};

