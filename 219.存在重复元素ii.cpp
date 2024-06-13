// 219.存在重复元素ii

// 1.哈希表
class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k){
		unordered_map<int,int> dictionary;
		int length = nums.size();
		for (int i = 0; i < length; ++i) {
			int num = nums[i];
			if (dictionary.count(num) && i - dictionary[num] <= k){
				return true;
			}
			dictionary[num] = i;
		}
		return false;
	}
};

// 2.滑动窗口
class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k){
		unordered_set<int> s;
		int length = nums.size();
		for (int i = 0; i < length; ++i) {
			if(i > k ){
				s.erase(nums[i-k-1]);
			}
			if(s.count(nums[i])){
				return true;
			}
			s.emplace(nums[i]);
		}
		return false;
	}
};