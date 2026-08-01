class Solution {
	public:
	int make_possible(vector<int> &arr, int mid)
	{
		int sum=0;
		int count=1;
		
		for(int i=0;i<arr.size();i++)
		{   
		    sum+=arr[i];
		    if(sum>mid)
		    {
		        count++;
		        sum=arr[i];
		    }
		}
		return count;
	}
	int minTime(vector<int>& arr, int k) {
		// code here
		int i = *max_element(arr.begin(), arr.end());
		int j = accumulate(arr.begin(), arr.end(), 0);
		int ans = j;
		while (i <= j)
			{
			int mid = i + (j - i)/2;
			
			if (make_possible(arr, mid) <= k)
				{
				ans = mid;
				j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return ans;
	}
};
