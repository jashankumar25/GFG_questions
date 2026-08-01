class Solution {
	public:
	int make_possible(vector<int> &arr, int mid)
	{
		int cow = 1;
		int lastpos = arr[0];
		
		for (int i = 1; i<arr.size(); i++)
			{
			if (arr[i]-lastpos >= mid)
				{
				cow++;
				lastpos = arr[i];
			}
		}
		return cow;
		
	}
	int aggressiveCows(vector<int> &arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		
		int i = 1;
		int j = arr.back() - arr.front();
		int ans = 0;
		while (i <= j)
			{
			int mid = i + (j - i)/2;
			
			if (make_possible(arr, mid)>=k)
			{
				ans = mid;
				i = mid + 1;
			}
			else {
				j = mid - 1;
			}
		}
		return ans;
	}
};
