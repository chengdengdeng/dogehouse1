// 242.有效字母异位词

// 1.排序(这算作弊吧。。
class Solution{
public:
	bool isAnagram(string s, string t){
		if (s.length() != t.length()){
			return false;
		}
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		return s == t;
	}
};

// 2.哈希
class Solution{
public:
	bool isAnagram(string s,string t){
		if(s.length() != t.length()){
			return false;
		}
		vector<int> table(26,0);
		for (auto & ch : s) {
			table[ch - 'a']++;
		}
		for (auto & ch : t) {
			table[ch - 'a']--;
			if(table[ch - 'a'] < 0){
				return false;
			}
		}
		return true;
	}
};