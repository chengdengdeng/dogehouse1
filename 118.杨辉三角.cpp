//118.杨辉三角

//经典！给定输入的行数，要去输出杨辉三角。resize...肯定又要卡我好久
class Solution{
public:
	vector<vector<int>> generate(int numRows){
		vector<vector<int>> ret(numRows);
		for (int i = 0; i < numRows; ++i){
			ret[i].resize(i + 1);
			ret[i][0] = ret[i][i] = 1;
			for (int j = 0; j < i; j++){
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
		return ret;
	}
};