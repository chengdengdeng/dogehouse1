//14.最长公共前缀：给定字符串数组，若无输出空字符串
//这道题的代码有点长，不是特别好理解，需要反刍

//横向扫描，套娃……思路不难，代码的熟练度还有待提升。。。
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(!strs.size()){
            return "";
        }

        string prefix = strs[0];
        int count = strs.size();
        for(int i = 1; i < count; i++){
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(!prefix.size()){
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1,const string& str2){
        int length = min(str1.size(),str2.size());
        int index = 0;
        while(index < length && str1[index] == str2[index]){
            ++index;
        }
        return str1.substr(0,index);
    }
};

//纵向扫描，不同于横向一个个比，直接一起比了。依然不难理解思路，需要熟悉代码。。。
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(!strs.size()){
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for(int i = 0 ; i < length;i++){
            char c = strs[0][i];
            for(int j = 1; j < count; j++){
                if(i == strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
}

//分治法 LCP满足结合律 时间空间复杂度并未提升，优点也许在于对于分治法的熟悉？
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(!strs.size()){
            return "";
        }
        else{
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string longestCommonPrefix(const vector<string>& strs,int start,int end){
        if(start == end){
            return strs[start];
        }
        else{
            int mid = (start + end)/2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid+1, end);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(const string& lcpLeft, const string& lcpRight){
        int minLength = min(lcpLeft.size(),lcpRight.size());
        for(int i = 0;i < minLength;i++){
            if(lcpLeft[i] != lcpRight[i]){
                return lcpLeft.substr(0,i);
            }
        }
        return lcpLeft.substr(0,minLength);
    }
};

//二分查找,时间消耗更多了...
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(!strs.size()){
            return "";
        }
        int minLength = min_element(strs.begin(), strs.end(),[](const string& s, const string& t){return s.size() < t.size();})->size();
        //可怕的一步，papertiger,下面就是很经典的二分查找啦
        int low = 0,high = minLength;
        while(low < high){
            int mid = (high - low + 1)/2 + low;
            if(isCommonPrefix(strs,mid)){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        return strs[0].substr(0,low);
    }

    bool isCommonPrefix(const vector<string>& strs,int length){
        string str0 = strs[0].substr(0,length);
        int count = strs.size();
        for(int i = 1; i < count; i++){
            string str = strs[i];
            for(int j - 0; j < length; j++){
                if(str0[j] != str[j]){
                    return false;
                }
            }
        }
        return true;
    }
};
