
class Solution {
	public:
	int make_possible(vector<int>& stations, double dist)
	{
		int cnt = 0;
		
		for (int i = 1; i < stations.size(); i++)
			{
			double gap = stations[i] - stations[i - 1];
			
			cnt += (int)(gap / dist);
			
			if (fmod(gap, dist) == 0)
				cnt--;
		}
		
		return cnt;
	}
	double minMaxDist(vector<int> &stations, int k) {
		// Code here
		double low = 0;
		double high = stations.back() - stations.front();
		
		while (high - low > 1e-6)
			{
			double mid = low + (high - low) / 2.0;
			
			if (make_possible(stations, mid) <= k)
				high = mid;
			else
				low = mid;
		}
		
		return high;
	}
};
