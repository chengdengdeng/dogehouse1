//9.回文数判别，给一个整数，判断是否为回文数。

//双指针法，整数转字符串
class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0) return false;
        string str = to_string(x);
        int left = 0;
        int right = str.size() - 1;
        while(left <= right){
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
}

//构造法（优化），取某一位的数字
class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        //排除掉末位为0的情况
        long reverseNum = 0;
        while(x > reverseNum){
            int last = x % 10;
            reverseNum = reverseNum * 10 + last;
            x = x/10;
        }
        return reverseNum == x || (reverse / 10) == x;
        //循环结束后，偶数位直接判断。奇数位r位数比x多1。
    }
}