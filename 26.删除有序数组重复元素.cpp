//26.删除有序数组中的重复项:删除重复的元素并返回长度

//快慢指针
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int length = nums.size();
        if(length == 0 ) return 0;
        int slow = 0,fast = 1;
        while(fast < length){
            if(nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};