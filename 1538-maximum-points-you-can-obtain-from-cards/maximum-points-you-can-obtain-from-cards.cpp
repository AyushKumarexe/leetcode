class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
     int i = nums.size()-k; 
     int sum =0;
     for(int l = i ;l<nums.size();l++)
     {
        sum+=nums[l];
     } 
  int temp = sum;
     for(int j = 0;j<k;j++)
     {
        temp = temp + nums[j]-nums[i%nums.size()];
        sum = max(temp,sum);
        i++;
     } 
     return sum;
    }
};