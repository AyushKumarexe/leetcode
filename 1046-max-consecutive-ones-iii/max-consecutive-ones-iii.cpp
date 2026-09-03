class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans =0;
        int temp =0;
        int j = 0;
     for(int i =0;i<nums.size();i++)
     {
      temp+=nums[i];
      if(temp +k<i-j +1) 
      {
        temp -= nums[j];
        j++;
      }
    ans = max(ans,i-j +1);
     }  
     return ans; 
    }
};