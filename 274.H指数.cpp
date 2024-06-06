//274.H指数

//虚假的中等难度题 哼哼
//1.排序
class Solution{
public:
	int hIndex(vector<int>& citations){
		sort(citations.begin(),citations.end());
		int h = 0,i = citations.size() - 1;
		while(i >= 0 && citations[i] > h){
			h++;
			i--;
		}
		return h;
	}
};

//2.计数排序
class Solution{
public:
	int hIndex(vector<int>& citations){
		int n = citations.size(),tot = 0;
		vector<int> counter(n+1);
		for (int i = 0; i < n; ++i) {
			if (citations[i] >= n){
				counter[n] ++;
			} else{
				counter[citations[i]] ++;
			}
		}
		for (int i = n; i >= 0; i--) {
			tot += counter[i];
			if(tot >= i){
				return i;
			}
		}
		return 0;
	}
};

//3.二分查找
class Solution{
public:
	int hIndex(vector<int>& citations){
		int left = 0,right = citations.size();
		int mid = 0, cnt = 0;
		while(left < right){
			mid = (left + right + 1) >> 1;
			cnt = 0;
			for (int i = 0; i < citations.size(); ++i) {
				if(citations[i] >= mid){
					cnt++;
				}
			}
			if(cnt >= mid){
				left = mid;
			} else{
				right = mid - 1;
			}
		}
		return left;
	}
};