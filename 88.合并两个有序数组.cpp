//88.合并两个有序数组

//直接合并排序（汗
class Solution{
public:
	void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
		for (int i = 0; i < n; ++i){
			nums1[m + i] = nums2[i];
		}
		sort(nums1.begin(),nums1.end());
	}
};

//双指针
class Solution{
public:
	void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
		int p1 = 0,p2 = 0;
		int sorted[m+n];
		int cur;
		while(p1 < m || p2 < n ){
			if(p1 == m){
				cur = nums2[p2++];
			}else if(p2 == n){
				cur = nums1[p1++];
			}else if(nums1[p1] < nums2[p2]){
				cur = nums1[p1++];
			}else{
				cur = nums2[p2++];
			}
			sorted[p1 + p2 - 1] = cur;
		}
		for (int i = 0; i != m+n ; ++i){
			nums1[i] = sorted[i];
		}
	}
};

//逆向双指针
class Solution{
public:
	void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
		int p1 = m - 1,p2 = n - 1;
		int tail = m + n - 1;
		int cur;
		while(p1 >= 0 || p2 >= 0){
			if(p1 == -1){
				cur = nums2[p2--];
			}else if(p2 == -1){
				cur = nums1[p1--];
			}else if(nums1[p1] > nums2[p2]){
				cur = nums1[p1--];
			}else{
				cur = nums2[p2--];
			}
			nums1[tail--] = cur;
		}
	}
};