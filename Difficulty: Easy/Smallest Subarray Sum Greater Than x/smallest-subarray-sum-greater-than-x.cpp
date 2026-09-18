class Solution {
	public:
	int smallestSubWithSum(int x, vector<int>& arr) {
		// code here
		
		int left = 0;
		int sum = 0;
		int result = INT_MAX;
		
		for (int right = 0; right<arr.size(); right++)
			{
			sum += arr[right];
			
			while (sum > x)
				{
				result = min(result, right - left + 1);
				sum -= arr[left];
				left++;
			}
		}
		if (result == INT_MAX)
			return 0;
		return result;
	}
};
