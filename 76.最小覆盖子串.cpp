// 76.最小覆盖子串

//滑动窗口，还是有点难，注意1和l
class Solution{
public:
	unordered_map<char,int> ori,cnt;
	bool check(){
		for (const auto &p : ori) {
			if ((cnt[p.first] < p.second)){
				return false;
			}
		}
		return true;
	}

	string minWindow(string s,string t){
		for (const auto &c : t) {
			++ori[c];
		}

		int l = 0,r = -1;
		int len = INT_MAX,ansL = -1,ansR = -1;

		while(r < int(s.size())){
			if (ori.find(s[++r]) != ori.end()){
				++cnt[s[r]];
			}
			while(check() && l <= r){
				if (r - l + 1 < len){
					len = r - l + 1;
					ansL = l;
				}
				l++;
			}
		}
		return ansL == -1 ? string() : s.substr(ansL,len);
	}
};