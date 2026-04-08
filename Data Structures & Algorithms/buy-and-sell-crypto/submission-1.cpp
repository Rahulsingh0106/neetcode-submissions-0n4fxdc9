class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int price : prices){
            if(minPrice > price){
                minPrice = price;
            }else{
                int profit = price - minPrice;
                maxProfit = max(profit, maxProfit);
            }
        }
        return maxProfit;
    }};
