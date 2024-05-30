//20.有效括号,判断

//栈（经典）消消乐^_^
//1.多了左括号 2.括号对不匹配 3.多了右括号---遇到左括号，将右括号入栈*
class  Solution{
public:
    bool  isValid(string s){
        stack<int> st;
        if(s.size() % 2 != 0) return false;

        for(int i = 0; i < s.size(); i++){
             //遇到左括号的场景
             if(s[i] == '(') st.push(')');
             else if(s[i] == '{') st.push('}');
             else if(s[i] == '[') st.push(']');
            //遇到右括号的场景
             else if(st.empty() || st.top() != s[i]) return false;
             else st.pop();
        }
        return st.empty();
    }
};