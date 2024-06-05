//80.删除有序数组中2个重复项

//双指针
class Solution{
public:
	int removeDuplicates(vector<int> & nums){
		int n = nums.size();
		if (n <= 2){
			return n;
		}
		int slow = 2,fast = 2;
		while(fast < n){
			if (nums[slow - 2] != nums[fast]){
				nums[slow] = nums[fast];
				slow++;
			}
			fast++;
		}
		return slow;
	}
};

//通用解法，应该要掌握！
class Solution{
public:
	int work(vector<int>& nums,int k){
		int len = 0;
		for (auto num : nums)
			if(len < k || nums[len - k] != num)
				nums[len++] = num;
		return len;
	}

	int remodeDuplicates(vector<int>& nums){
		return work(nums,2);
	}
};