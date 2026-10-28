class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int size = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
           size = max(size, (int)nums[i].size());
        }
        vector<vector<int>> dig(nums.size() +size);
        for(int i =0;i < nums.size();i++)
        {
         for(int j =0;j<nums[i].size();j++)
         {
            dig[i+j].push_back(nums[i][j]);
         }
        }
     for(int i =0;i<nums.size() +size;i++)
     {
          for (int j = (int)dig[i].size() - 1; j >= 0; j--) {
                ans.push_back(dig[i][j]);
            }
     }
     return ans;
    }
};