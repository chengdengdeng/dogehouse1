// 48.旋转图像

// 暴力，引入数组
class Solution{
public:
	voir rotate(vector<vector<int>>& matrix){
		int n = matrix.size();
		auto matrix_new = matrix;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matrix_new[j][n-1-i] = matrix[i][j];
			}
		}
		matrix = matrix_new;
	}
};

// 原地旋转，四项打转
class Solution{
public:
	void rotate(vector<vector<int>>& matrix){
		int n = matrix.size();
		for (int i = 0; i < n/2; ++i) {
			for (int j = 0; j < (n+1)/2; ++j) {
				int t = matrix[i][j];
				matrix[i][j] = matrix[n-j-1][i];
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = t;
			}
		}
	}
};

// 翻转
class Solution{
public:
	void  rotate(vector<vector<int>> & matrix){
		int n = matrix.size();
		for (int i = 0; i < n/2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j],matrix[n-1-i][j]);
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j],matrix[j][i]);
			}
		}
	}
};