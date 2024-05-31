//58.最后一个单词的长度

//后序遍历
class Solution{
public:
	int lengthOfLastWord(string s){
		int n = s.size();
		int cnt = 0;
		for (int i = n; i >= 0; i--){
			if (s[i] != ' '){
				cnt++;
			} else if (cnt != 0){
				break;
			}
		}
		return cnt;
	}
};