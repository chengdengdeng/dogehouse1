// 150.逆波兰表达式求值

// 1.栈 经典做法
class Solution{
public:
	int evalRPN(vector<string>& tokens){
		stack<int> stk;
		int n = tokens.size();
		for (int i = 0; i < n; ++i) {
			string& token = tokens[i];
			if (isNumber(token)){
				stk.push(atoi(token.c_str()));
			} else{
				int num2 = stk.top();
				stk.pop();
				int num1 = stk.top();
				stk.pop();
				switch (token[0]) {
					case '+' :
						stk.push(num1 + num2);
						break;
					case '-':
						stk.push(num1 - num2);
						break;
					case '*':
						stk.push(num1 * num2);
						break;
					case '/':
						stk.push(num1 / num2);
						break;
				}
			}
		}
		return stk.top();
	}
	bool isNumber(string & token){
		return !(token == "+" || token == "-" || token == "*" || token == "/");
	}
};

// 2.数组模拟栈？？？
class Solution{
public:
	int evalRPN(vector<string>& tokens){
		int n = tokens.size();
		vector<int> stk((n+1)/2);
		int index = -1;
		for (int i = 0; i < n; ++i) {
			string& token = tokens[i];
			if(token.length() > 1 || isdigit(token[0])){
				index++;
				stk[index] = atoi(token.c_str());
			} else{
				switch(token[0]){
					case '+':
						index--;
						stk[index] += stk[index + 1];
						break;
					case '-':
						index--;
						stk[index] -= stk[index + 1];
						break;
					case '*':
						index--;
						stk[index] *= stk[index + 1];
						break;
					case '/':
						index--;
						stk[index] /= stk[index + 1];
						break;
				}
			}
		}
		return stk[index];
	}
};