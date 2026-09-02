class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int left=0;
        int sum=0;
        int ans=INT_MIN;
        
        for(int right=0;right<arr.size();right++)
        {
            sum+=arr[right];
            
            if(right-left+1==k)
            {
                ans=max(ans,sum);
                sum-=arr[left];
                left++;
            }
        }
        return ans;
    }
};