//69.x的平方根

//1.袖珍计算器法
class Solution{
public:
	int mySqrt(int x){
		if (x == 0){
			return 0;
		}
		int ans = exp(0.5 * log(x));
		return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1: ans);
	}
};

//2.二分查找
class Solution{
public:
	int mySqrt(int x){
		int l = 0, r = x, ans = -1;
		while(l <= r){
			int mid = 1 + (r - 1) / 2;
			if((long long) mid * mid <= x){
				ans = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		return ans;
	}
};

//3.**牛顿迭代
class Solution{
public:
	int mySqrt(int x){
		if(x == 0){
			return 0;
		}

		double C = x,x0 = x;
		while(true){
			double xi = 0.5 * (x0 + C/x0);
			if(fab(x0 - xi) < 1e-7){
				break;
			}
			x0 = xi;
		}
		return int(x0);
	}
};