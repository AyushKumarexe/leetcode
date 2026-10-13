class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int k =0;k<nums.size();k++)
        {
        if(nums[k]<0)nums[k]= nums[k]*-1;
        }
     sort(nums.begin(),nums.end());
     int i = nums.size()/2;
     int l =i;
     long long ans =0;
     for(i;i<nums.size();i++)
     {
        ans+=nums[i]*nums[i];
     }
     for(int j =0;j<l;j++)
     {
         ans-=nums[j]*nums[j];
     }
     return ans;
    }
};