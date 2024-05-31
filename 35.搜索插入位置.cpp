//35.搜索插入位置

//二分查找^_^ 稍微修改一下
class Solution{
public:
	int searchInsert(vector<int>& nums,int target){
		int n = nums.size();
		int left = 0,right = n - 1,pos = n;
		while(left <= right){
			int mid = ((right - left) >> 1) + left;
			if (target <= nums[mid]){
				pos = mid;
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}
		return pos;
	}
};

