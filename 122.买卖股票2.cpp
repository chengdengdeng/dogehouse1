// 122.买卖股票2

/*
 * 动态规划--有点小题大做了，不过可以锻炼锻炼思维手感
 */
class Solution{
public:
	int maxProfit(vector<int>& prices){
		int n = prices.size();
		int dp[n][2];
		dp[0][0] = 0,dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
			dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
		}
		return dp[n-1][0];
	}
};

class Soulution{
public:
	int maxProfit(vector<int>& prices){
		int n = prices.size();
		int dp0 = 0,dp1 = -prices[0];
		for (int i = 1; i < n; ++i) {
			int newDp0 = max(dp0,dp1 + prices[i]);
			int newDp1 = max(dp1,dp0 - prices[i]);
			dp0 = newDp0;
			dp1 = newDp1;
		}
		return dp0;
	}
};

//贪心法，合乎逻辑
class Solution{
public:
	int maxProfit(vector<int>& prices){
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			int tmp = prices[i] - prices[i-1];
			if(tmp > 0) profit += tmp;
		}
		return profit;
	}
};