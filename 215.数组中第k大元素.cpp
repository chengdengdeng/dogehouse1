// 215.数组中第k大元素

// 快速排序
class Solution{
public:
	int quickselect(vector<int> &nums,int l,int r,int k){
		if (l == r){
			return nums[k];
		}
		int partition = nums[l], i = l - 1, j = r + 1;
		while(i < j){
			do i++;while(nums[i] < partition);
			do j++;while(nums[j] > partition);
			if (i < j){
				swap(nums[i],nums[j]);
			}
		}
		if (k <= j) return quickselect(nums,l,j,k);
		else return quickselect(nums,j+1,r,k);
	}

	int findKthLargest(vector<int> &nums,int k){
		int n = nums.size();
		return quickselect(nums,0,n-1,n-k);
	}
};

// 2.堆排序
class Solution{
public:
	void maxHeapify(vector<int> &a,int i,int heapSize){
		int l = i * 2 + 1, r = i * 2 + 2,largest = i ;
		if(l < heapSize && a[l] > a[largest]){
			largest = l;
		}
		if(r < heapSize && a[r] > a[largest]){
			largest = r;
		}
		if(largest != i){
			swap(a[i],a[largest]);
			maxHeapify(a,largest,heapSize);
		}
	}

	void buildMaxHeap(vector<int> &a,int heapSize){
		for (int i = heapSize/2; i >= 0; i--) {
			maxHeapify(a,i,heapSize);
		}
	}

	int findKthLargest(vector<int> &nums,int k){
		int heapSize = nums.size();
		buildMaxHeap(nums,heapSize);
		for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--) {
			swap(nums[0],nums[i]);
			heapSize--;
			maxHeapify(nums,0,heapSize);
		}
		return nums[0];
	}
};