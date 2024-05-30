//1.两数之和：给一个整数数组和目标值，在数组中，找出和为目标值的两个整数的下标。

//暴力
class Solution {
public:
    vector<int> twoSum(vector<int> & number,int target){
        int i , j ;
        for(i = 0; i < nums.size() - 1; i++)
            for(j = i + 1; j < nums.size(); j++)
                if(nums[i] + nums[j] == target)
                    return { i , j };
        return { i , j };
    } 
}

//哈希：判断元素是否在集合中遍历过，map存储遍历过的元素及下标
//unordered_map 存和读效率最高

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> hash;
            for(int i = 0 ; i < nums.size(); i ++){
                auto it = hash.find(target - nums[i]);//***map的调用还不太熟悉
                if(it != hash.end()){
                    return {it->second , i};
                }
                hash[nums[i]] = i;//map存储该元素
            }
            return { };
}
