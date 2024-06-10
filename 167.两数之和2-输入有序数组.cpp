// 167.两数之和2-输入有序数组

//1.双指针
class Solution{
	vector<int> twoSum(vector<int>& numbers,int target){
		int i = 0;
		int j = numbers.size() - 1;
		while(i < j){
			int sum = numbers[i] + numbers[j];
			if (sum < target){
				i++;
			} else if (sum > target){
				j--;
			} else{
				return vector<int> {i+1,j+1};
			}
		}
		return vector<int>{-1,-1};
	}
};

//2.二分查找
class Solution{
public:
	vector<int> twoSum(vector<int>& numbers,int target){
		for (int i = 0; i < numbers.size(); ++i) {
			int low = i + 1,high = numbers.size() - 1;
			while(low <= high){
				int mid = (high - low)/2 + low;
				if(numbers[mid] == target - numbers[i]){
					return {i + 1,mid + 1};
				} else if(numbers[mid] > target - numbers[i]){
					high = mid - 1;
				} else{
					low = mid + 1;
				}
			}
		}
		return {-1,-1};
	}
};