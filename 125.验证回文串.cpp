//125.验证回文串

//学到了很多函数--isalnum/tolower/rev
class Solution{
public:
	bool isPalindrome(string s){
		string sgood;
		for (char ch:s){
			if (isalnum(ch)){
				sgood += tolower(ch);
			}
		}
		string sgood_rev(sgood.rbegin(),sgood.rend());
		return sgood == sgood_rev;
	}
};

//双指针
class Solution{
	bool isPalindrome(string s){
		string sgood;
		for (char ch:s){
			if(isalnum(ch)){
				sgood += tolower(ch);
			}
		}
		int n = sgood.size();
		int left = 0.right = n - 1;
		while(left < right){
			if(sgood[left] != sgood[right]){
				return false;
			}
			left ++;
			right --;
		}
		return true;
	}
};

//直接判断
class Solution{
public:
	bool isPalindrome(string s){
		int n = s.size();
		int left = 0, right = n - 1;
		while(left < right){
			while(left < right && !isalnum(s[left])){
				left ++;
			}
			while(left < right && !isalnum(s[right])){
				right --;
			}
			if(left < right){
				if(tolower(s[left]) != tolower(s[right])){
					return false;
				}
				left ++;
				right --;
			}
		}
		return true;
	}
};