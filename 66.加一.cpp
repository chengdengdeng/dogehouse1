//66.加一

//主要考虑9的情况
class Solution{
public:
	vector<int> plusOne(vector<int>& digits){
		int n = digits.size();
		for (int i = n - 1; i >= 0 ; --i){
			if (digits[i] != 9){
				digits[i]++;
				for (int j = n + 1; j < n; ++j){
					digits[j] = 0;
				}
				return digits;
			}
		}

		vector<int> ans(n + 1);
		ans[0] = 1;
		return ans;
	}
};
