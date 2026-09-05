class Solution {
    void dfs(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&output)
    {
        if (i >= nums.size()) {
            ans.push_back(output);
            return;
        }

        output.push_back(nums[i]);
     dfs( i +1,nums,ans,output);
      int next = i+1;
     while(next<nums.size()&&nums[next]==nums[i])next++;
     output.pop_back();
     dfs( next,nums,ans,output);  
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>output;
     sort(nums.begin(),nums.end());
      dfs(0,nums,ans,output);
      return ans;
    }
};