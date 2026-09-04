class Solution {
void dfs(int i,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&output)
{
     if(target ==0)
    {
     ans.push_back(output);
     return; 
    }
       if (i >= nums.size() || nums[i] > target) return; 
     output.push_back(nums[i]);
      dfs(i+1,nums,target-nums[i],ans,output);
           output.pop_back();
      int next = i + 1;
          while (next < nums.size() && nums[next] == nums[i]) next++;
     dfs(next,nums,target,ans,output);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int>output;
      vector<vector<int>>ans;
      sort(candidates.begin(),candidates.end());
     dfs(0,candidates,target,ans,output);
     return ans;
    }
};