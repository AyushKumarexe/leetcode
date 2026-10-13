class Solution {
public:
    int maxProfit(vector<int>& prices) {
   if(prices.size()==1)return 0;
   int man = prices[0];
   int ans  =0;
    for(int i =1;i<prices.size();i++)
    {
   if(prices[i]-man>ans)ans = prices[i]-man;
   man = min(prices[i],man);
    }
    return ans;
    }
};