// 202.快乐数

// 快慢指针破坏循环(值得借鉴的思路）
class Solution{
public:
	int bitsquareSum(int n){
		int sum = 0;
		while(n >0){
			int bit = n % 10;
			sum += bit * bit;
			n = n/10;
		}
		return sum;
	}

	bool isHappy(int n){
		int slow = n,fast = n;
		do{
			slow = bitsquareSum(slow);
			fast = bitsquareSum(fast);
			fast = bitsquareSum(fast);
		} while(slow != fast);

		return slow == 1;
	}
};