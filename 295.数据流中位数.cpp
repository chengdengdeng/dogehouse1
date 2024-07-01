// 295.数据流中位数

// 优先队列
class MedianFinder {
public:
	priority_queue<int, vector<int>, less<int>> queMin;
	priority_queue<int, vector<int>, greater<int>> queMax;

	MedianFinder() {}

	void addNum(int num) {
		if (queMin.empty() || num <= queMin.top()) {
			queMin.push(num);
			if (queMax.size() + 1 < queMin.size()) {
				queMax.push(queMin.top());
				queMin.pop();
			}
		} else {
			queMax.push(num);
			if (queMax.size() > queMin.size()) {
				queMin.push(queMax.top());
				queMax.pop();
			}
		}
	}

	double findMedian() {
		if (queMin.size() > queMax.size()) {
			return queMin.top();
		}
		return (queMin.top() + queMax.top()) / 2.0;
	}
};

// 2.双指针
class MedianFinder {
	multiset<int> nums;
	multiset<int>::iterator left, right;

public:
	MedianFinder() : left(nums.end()), right(nums.end()) {}

	void addNum(int num) {
		const size_t n = nums.size();

		nums.insert(num);
		if (!n) {
			left = right = nums.begin();
		} else if (n & 1) {
			if (num < *left) {
				left--;
			} else {
				right++;
			}
		} else {
			if (num > *left && num < *right) {
				left++;
				right--;
			} else if (num >= *right) {
				left++;
			} else {
				right--;
				left = right;
			}
		}
	}

	double findMedian() {
		return (*left + *right) / 2.0;
	}
};