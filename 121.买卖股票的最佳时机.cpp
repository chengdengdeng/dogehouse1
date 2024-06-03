//121.买卖股票的最佳时机

//暴力法（超时）
class Solution{
public:
	int maxProfit(vector<int>& prices){
		int n = (int)prices.size(),ans = 0;
		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				ans = max(ans,prices[j] - prices[i]);
			}
		}
		return ans;
	}
};

//遍历
class Solution{
public:
	int maxProfit(vector<int>& prices){
		int inf = 1e9;
		int minprice = inf,maxprofit = 0;
		for (int price:prices){
			maxprofit = max(maxprofit,price - minprice);
			minprice = min(price,minprice);
		}
		return maxprofit;
	}
};