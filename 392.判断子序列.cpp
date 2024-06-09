// 392.判断子序列

// 1.双指针
class Solution{
public:
	bool isSubsequence(string s,string t){
		int n = s.length(),m = t.length();
		int i = 0,j = 0;
		while(i < n && j < m){
			if (s[i] == t[j]){
				i++;
			}
			j++;
		}
		return i == n;
	}
};

// 2.动态规划
class Solution{
public:
	bool isSubsequence(string s,string t){
		int n = s.size(),m = t.size();
		vector<vector<int>> f(m+1,vector<int>(26,0));

		for (int i = 0; i < 26; ++i) {
			f[m][i] = m ;
		}

		for (int i = m-1; i >= 0 ; i--) {
			for(int j = 0;j < 26;j++){
				if(t[i] == j + 'a'){
					f[i][j] = i;
				} else{
					f[i][j] = f[i+1][j];
				}
			}
		}

		int add = 0;
		for (int i = 0; i < n; ++i) {
			if(f[add][s[i]-'a'] == m){
				return false;
			}
			add = f[add][s[i]-'a'] + 1;
		}
		return true;
	}
};