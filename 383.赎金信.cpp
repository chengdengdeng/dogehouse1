// 383.赎金信

//1.计数
class Solution{
public:
	bool canConstruct(string ransomNote,string magazine){
		if (ransomNote.size() > magazine.size()){
			return false;
		}
		vector<int> cnt(26);
		for (auto & c : magazine) {
			cnt[c - 'a']++;
		}
		for (auto & c : ransomNote) {
			cnt[c - 'a']--;
			if (cnt[c - 'a'] < 0){
				return false;
			}
		}
		return true;
	}
};

//哈希
class Solution{
public:
	bool canConstruct(string ransomNote,string magazine){
		unordered_map<char ,int> u_m;

		for (auto ch : magazine) {
			++u_m[ch];
		}
		for (auto ch : ransomNote) {
			if(u_m[ch] == 0){
				return false;
			}
			--u_m[ch];
		}
		return true;
	}
};