//119.杨辉三角2

//递推,参考上一题
class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<vector<int>> C(rowIndex + 1);
		for (int i = 0; i <= rowIndex; ++i){
			C[i].resize(i+1);
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j){
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
		return C[rowIndex];
 	}
};

//优化
class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<int> row(rowIndex + 1);
		row[0] = 1;
		for (int i = 1; i <= rowIndex; ++i){
			for (int j = i; j > 0; j--){
				row[j] += row[j - 1];
			}
		}
		return row;
	}
};

//线性递推（公式法）
class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<int> row(rowIndex + 1);
		row[0] = 1;
		for (int i = 1; i < rowIndex + 1; ++i){
			row[i] = 1LL * row[i-1] * (rowIndex - i + 1)/ i;//1LL类型转换
		}
		return row;
	}
};