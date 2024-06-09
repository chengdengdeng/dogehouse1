//151.翻转单词

//两次翻转
class Solution{
public:
	string reverseWords(string s){
		reverse(s.begin(),s.end());

		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' '){
				if (idx != 0) s[idx++] = ' ';

				int end = start;
				while(end < n && s[end] != ' '){
					s[idx++] = s[end++];
				}
				reverse(s.begin() + idx - (end - start),s.begin() + idx);
				start = end;
			}
		}
		s.erase(s.begin() + idx,s.end());
		return s;
	}
};

//双端队列
class Solution{
public:
	string reverseWords(string s){
		int left = 0,right = s.size() - 1;
		while(left <= right && s[left] == ' ') left++;
		while(left <= right && s[right] == ' ') right--;

		deque<string> d;
		string word;

		while(left <= right){
			char c = s[left];
			if(word.size() && c == ' '){
				d.push_front(move(word));
				word = " ";
			}else if(c != ' '){
				word += c;
			}
			left++;
		}
		d.push_front(move(word));

		string ans;
		while(!d.empty()){
			ans += d.front();
			d.pop_front();
			if(!d.empty()) ans += ' ';
		}
		return ans;
	}
};