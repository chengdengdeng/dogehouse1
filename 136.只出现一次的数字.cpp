//136.只出现一次的数字

//位运算
class Solution{
public:
	int singleNumber(vector<int> & nums){
		int ret = 0;
		for (auto e:nums){
			ret ^= e;
		}
		return ret;
	}
};