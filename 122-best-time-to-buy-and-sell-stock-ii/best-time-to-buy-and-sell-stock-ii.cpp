class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int Min = prices[0];
      int profit =0;
      for(int i=1;i<prices.size();i++)
      {
        if(prices[i]-Min>0)
        {
        profit+=prices[i]-Min;
        Min = prices[i];
        }
        else
        Min = min(Min,prices[i]);
      }  
      return profit;
    }
};