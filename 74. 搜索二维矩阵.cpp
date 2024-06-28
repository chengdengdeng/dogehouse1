// 74.搜索二维矩阵

// 1.两次二分
class Solution{
public:
	bool searchMatrix(vector<vector<int>> matrix,int target){
		auto row = upper_bound(matrix.begin(),matrix.end(),target,[](const int b,const vector<int> &a){
			return b < a[0];
		});
		if (row == matrix.begin()){
			return false;
		}
		row--;
		return binary_search(row->begin(),row->end(),target);
	}
};

// 2.一次二分
class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix,int target){
		int m = matrix.size(),n = matrix[0].size();
		int low = 0,high = m * n - 1;
		while(low <= high){
			int mid = (high - low)/2 + low;
			int x = matrix[mid/n][mid%n];
			if(x < target){
				low = mid + 1;
			}else if (x > target){
				high = mid - 1;
			}else{
				return true;
			}
		}
		return false;
	}
};