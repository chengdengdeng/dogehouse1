//13.罗马数字转整数

//用map进行存储，核心在于与后一位的比较
class Solution{
public:
    unordered_map<char,int> symbolValues = {
        {'I',1}, {'V',5},{'X',10},{'L',50},
        {'C',100},{'D',500},{'M',1000}
    }
    
    int Roman-to-Int(string s){
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            int value = symbolValues[s[i]];
            if( i < s.length()-1 && value < symbolValues[s[i + 1]]){//小于右边的数字
                ans -= value;
            }else{
                ans += value;
            }
        }
        return ans;
    }
}

//快速***(why,应该是由于map的使用，深层原因？），代码略显笨拙（用switch改一下）
class Solution{
public:
    int Rooman-to-Int(string s){
        int sum = 0;
        int value = 0;
        int last = 0;
        //反向遍历
        for(int i = s.size() - 1 ; i >= 0 ; i--){
            if(s[i] == 'I') value = 5;
            else if(s[i] == 'X') value = 10;
            else if(s[i] == 'L') value = 50;
            else if(s[i] == 'C') value = 100;
            else if(s[i] == 'D') value = 500;
            else if(s[i] == 'M') value = 1000;

            if(sum != 0 && value < last){
                value = -value;
            }
            last = value;
            sum += value;
        }
        return sum;
    }
}
