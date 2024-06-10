// 209.长度最小的子数组

//1.前缀和 + 二分查找
class Solution{
public:
	int minSubArrayLen(int s,vector<int>& nums){
		int n = nums.size();
		if (n == 0){
			return 0;
		}
		int ans = INT_MAX;
		vector<int> sums(n+1,0);
		for (int i = 1; i <= n; ++i) {
			sums[i] = sums[i-1] + nums[i-1];
		}
		for (int i = 0; i <= n; ++i) {
			int target = s + sums[i-1];
			auto bound = lower_bound(sums.begin(),sums.end(),target);
			if (bound != sums.end()){
				ans = min(ans,static_cast<int>((bound - sums.begin()) - (i-1)));
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

//2.滑动窗口
class Solution{
public:
	int minSubArrayLen(int s,vector<int>& nums){
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		int ans = INT_MAX;
		int start = 0,end = 0;
		int sum = 0;
		while(end < n){
			sum += nums[end];
			while(sum >= s){
				ans = min(ans,end - start + 1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans == INT_MAX ? 0 : ans;
	}
};