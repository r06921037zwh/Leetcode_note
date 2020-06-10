class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int profit = 0, minPrice = prices[0], maxPrice = prices[0];
        for(int i=1; i<prices.size(); ++i){
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            }else{
                profit += maxPrice - minPrice;
                minPrice = maxPrice = prices[i];
            }
        }
        profit += maxPrice - minPrice;
        return profit;
    }
};
