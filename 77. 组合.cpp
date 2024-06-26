// 77.组合

// 1. 递归组合枚举
class Solution{
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(int cur,int n,int k){
		if (temp.size() + (n-cur+1) < k){
			return;
		}
		if (temp.size() == k){
			ans.push_back(temp);
			return;
		}
		temp.push_back(cur);
		dfs(cur+1,n,k);
		temp.pop_back();
		dfs(cur+1,n,k);
	}

	vector<vector<int>> combine(int n,int k){
		dfs(1,n,k);
		return ans;
	}
};

// 2.非递归（字典）组合枚举
class Solution{
public:
	vector<int> temp;
	vector<vector<int>> ans;

	vector<vector<int>> combine(int n,int k){
		for (int i = 1; i <= k; ++i) {
			temp.push_back(i);
		}
		temp.push_back(n+1);

		int j = 0;
		while(j < k){
			ans.emplace_back(temp.begin(),temp.begin() + k);
			j = 0;
			while(j < k && temp[j] + 1 == temp[j+1]){
				temp[j] = j +1;
				j++;
			}
			temp[j]++;
		}
		return ans;
	}
};