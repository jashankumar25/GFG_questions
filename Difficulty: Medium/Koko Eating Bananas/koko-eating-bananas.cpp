class Solution {
	public:
	int isvalid(vector<int>& arr, int mid)
	{
		int h=0;
		for (int i = 0; i<arr.size(); i++)
			{
			h += arr[i]/mid;
			
			if (arr[i]%mid != 0)
				h++;
		}
		return h;
	}
	int kokoEat(vector<int>& arr, int k) {
		// Code here
		int i = 1;
		int j = *max_element(arr.begin(), arr.end());
		int ans=j;
		while (i <= j)
			{
			int mid = i + (j - i)/2;
			
			if (isvalid(arr, mid)<=k)
				{
				ans = mid;
				j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return i;
	}
};
