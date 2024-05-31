//28.找出字符串中第一个匹配项的下标

//暴力解，匹配所有长度为 m 的子串
class Solution{
public:
	int strStr(string s,string p){
		int n = s.size(),m = p.size();
		for (int i = 0; i <= n - m; ++i){
			int j = i, k = 0;
			while(k < m && s[j] == p[k]){
				j++;
				k++;
			}
			if (k == m) return i;
		}
		return -1;
	}
};

//**KMP算法，next数组
//对匹配串进行处理（next数组），节约匹配的步骤
class Solution{
public:
	int strStr(string s,string p){
		int n = s.size(),m = p.size();
		if(m == 0) return 0;//健壮性考虑
		s.insert(s.begin(),'');
		p.insert(p.begin(),'');
		vector<int> next(m + 1);
		for (int i = 2, j = 0; i <= m; ++i){
			while(j && p[i] != p[j+1]) j = next[j];
			if(p[i] == p[j + 1]) j++;
			next[i] = j;
		}
		for (int i = 1,j = 0; i <= n ; ++i){
			while(j && s[i] != p[j + 1]) j = next[j];
			if(s[i] == p[j+1]) j++;
			if(j ==m) return i - m;
		}
		return -1;
	}
};
