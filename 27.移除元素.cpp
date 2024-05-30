 //27。移除元素

 //快慢指针still，可以和上一题进行对照
 class Solution{
    int removeElement(int* nums,int numsSize.int val){
        int slow = 0,fast = 0;
        while(fast < num.size()){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
 };