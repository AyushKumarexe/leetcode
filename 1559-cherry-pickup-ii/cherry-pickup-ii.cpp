class Solution {
    int dfs(int i,int j,int k, vector<vector<vector<int>>>&dp,vector<vector<int>>& grid)
    {
   if(j<0||j>=grid[0].size()||k<0||k>=grid[0].size()) return -1e9;
    if(i==grid.size()-1)
    {
        if(j==k)return grid[i][j];
        else
        return grid[i][j] + grid[i][k];
    }
    if(dp[i][j][k]!=-1e8) return dp[i][j][k];
  int  max_v = -1e8;
  for(int l = -1;l<2;l++)
  {
    for(int r = -1;r<2;r++)
    {
     int   value =0;
    if(j==k) value =grid[i][j];
    else
    {
   value = grid[i][j] + grid[i][k];
    }
    value+= dfs(i+1,j+l,k+r,dp,grid);
    max_v = max(value,max_v); 
     
    }
  
  }
 return dp[i][j][k] = max_v;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
 vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1e8)));
 return dfs( 0, 0, n-1,dp,grid);
    }
};