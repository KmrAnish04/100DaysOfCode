class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int amountToBuy = prices[0];
        int maxProfit = 0;
        
        // printf("%d",prices.size());
        
        if(prices.size()>1){
            
            for(int i=0 i<prices.size(); i++){
                if(prices[i]<amountToBuy){
                    amountToBuy = prices[i];
                }
            }
        }
        return maxProfit;
    }
};

